/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10", "NotoColorEmoji:pixelsize=10:antialias=true:autohint=true" };
static const char dmenufont[]       = "monospace:size=10";
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char termcol0[] = "#000000"; /* black   */
static char termcol1[] = "#ff0000"; /* red     */
static char termcol2[] = "#33ff00"; /* green   */
static char termcol3[] = "#ff0099"; /* yellow  */
static char termcol4[] = "#0066ff"; /* blue    */
static char termcol5[] = "#cc00ff"; /* magenta */
static char termcol6[] = "#00ffff"; /* cyan    */
static char termcol7[] = "#d0d0d0"; /* white   */
static char termcol8[]  = "#808080"; /* black   */
static char termcol9[]  = "#ff0000"; /* red     */
static char termcol10[] = "#33ff00"; /* green   */
static char termcol11[] = "#ff0099"; /* yellow  */
static char termcol12[] = "#0066ff"; /* blue    */
static char termcol13[] = "#cc00ff"; /* magenta */
static char termcol14[] = "#00ffff"; /* cyan    */
static char termcol15[] = "#ffffff"; /* white   */
static char *termcolor[] = {
  termcol0,
  termcol1,
  termcol2,
  termcol3,
  termcol4,
  termcol5,
  termcol6,
  termcol7,
  termcol8,
  termcol9,
  termcol10,
  termcol11,
  termcol12,
  termcol13,
  termcol14,
  termcol15,
};
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "80x25", "-e", "tmux", NULL };
const char *spcmd2[] = {"st", "-n", "spcalc", "-g", "40x20", "-e", "calc", NULL };
const char *spcmd3[] = {"keepassxc", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",       spcmd1},
	{"spcalc",       spcmd2},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance     title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,        NULL,       0,            0,           -1 },
	{ NULL,       "spterm",    NULL,       SPTAG(0),     1,           -1 },
	{ NULL,       "spcalc",    NULL,       SPTAG(1),     1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[B]",      bstack },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };

#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key        function          argument */
	// spawn and kill
	{ MODKEY,                       XK_Return, spawn,            {.v = termcmd } },
	{ MODKEY,                       XK_u,      togglescratch,    {.ui = 0 } },
	{ MODKEY,                       XK_a,      togglescratch,    {.ui = 1 } },
	{ MODKEY,                       XK_d,      spawn,            {.v = dmenucmd } },
	{ MODKEY,                       XK_grave,  spawn,            {.v = (const char*[]){ "dmenuunicode", NULL } } },
	{ MODKEY,                       XK_q,      killclient,       {0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,             {0} },
	{ MODKEY|Mod1Mask,              XK_q,      xrdb,             {.v = NULL } },
	// layout
	{ MODKEY,                       XK_Tab,    view,             {0} },
	{ MODKEY,                       XK_f,      setlayout,        {.v = &layouts[1]} },
	{ MODKEY|Mod1Mask,   		XK_comma,  cyclelayout,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_period, cyclelayout,      {.i = +1 } },
	{ MODKEY,                       XK_space,  setlayout,        {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating,   {0} },
	{ MODKEY,                       XK_b,      togglebar,        {0} },
	// stack position
	{ MODKEY|ShiftMask,             XK_Return, zoom,             {0} },
	{ MODKEY,                       XK_j,      focusstack,       {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,        {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,         {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,         {.f = +0.05} },
	// gaps
	{ MODKEY,                       XK_0,      togglegaps,       {0} },
	{ MODKEY|Mod1Mask,              XK_0,      defaultgaps,      {0} },
	{ MODKEY|Mod1Mask,              XK_j,      incrgaps,         {.i = +5 } },
	{ MODKEY|Mod1Mask,              XK_k,      incrgaps,         {.i = -5 } },
 	TAGKEYS(                        XK_1,                        0)
	TAGKEYS(                        XK_1,                        0)
	TAGKEYS(                        XK_2,                        1)
	TAGKEYS(                        XK_3,                        2)
	TAGKEYS(                        XK_4,                        3)
	TAGKEYS(                        XK_5,                        4)
	TAGKEYS(                        XK_6,                        5)
	TAGKEYS(                        XK_7,                        6)
	TAGKEYS(                        XK_8,                        7)
	TAGKEYS(                        XK_9,                        8)
	/*
	{ MODKEY|ControlMask,           XK_0,      tag,              {.ui = ~0 } }, // ???
	{ MODKEY,                       XK_0,      view,             {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,           {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,           {.i = +1 } },
	{ MODKEY,                       XK_comma,  focusmon,         {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,         {.i = +1 } },
	{ MODKEY,                       XK_i,      incnmaster,       {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,       {.i = -1 } },
	*/
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button1,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
