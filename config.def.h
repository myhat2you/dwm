/* See LICENSE file for copyright and license details. */

/* dependancies ================================*/
/* constants ===================================*/
#define TERMINAL "st"
#define TERMCLASS "St"
#define STATUSBAR "dwmblocks"
#define BROWSER "librewolf"
/* appearance ==================================*/
static const unsigned int borderpx  = 3;         /* border pixel of windows */
static const unsigned int snap      = 32;        /* snap pixel */
static const unsigned int gappih    = 10;        /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;        /* vert inner gap between windows */
static const unsigned int gappoh    = 15;        /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 15;        /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;         /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;         /* 0 means no bar */
static const int topbar             = 1;         /* 0 means bottom bar */
/* fonts =======================================*/
static const char *fonts[]    = { "monospace:size=10:bold", "Font Awesome 6 Free Solid:size=10" };
static const char dmenufont[] =   "monospace:size=10:bold";
/* colors ======================================*/
static char normbgcolor[]     = "#08080B";       /* bar background */
static char normfgcolor[]     = "#BBBBBB";       /* bar foreground */
static char normbordercolor[] = "#2B2B2B";       /* unfocused border */
static char selbgcolor[]      = "#4D6DD0";       /* selected background */
static char selfgcolor[]      = "#FAFAFA";       /* selected foreground */
static char selbordercolor[]  = "#ABABAB";       /* focused border */
/* terminal (light) ----------------------------*/
static char termcol0[]  = "#1C1C1C"; /* black   */
static char termcol1[]  = "#D42050"; /* red     */
static char termcol2[]  = "#00BB8F"; /* green   */
static char termcol3[]  = "#DD4D64"; /* yellow  */
static char termcol4[]  = "#4D6DD0"; /* blue    */
static char termcol5[]  = "#DA3060"; /* magenta */
static char termcol6[]  = "#10A0C8"; /* cyan    */
static char termcol7[]  = "#B0B0B0"; /* white   */
/* terminal (dark) -----------------------------*/
static char termcol8[]  = "#6E6E6E"; /* black   */
static char termcol9[]  = "#FF3565"; /* red     */
static char termcol10[] = "#10E0B0"; /* green   */
static char termcol11[] = "#DD4D64"; /* yellow  */
static char termcol12[] = "#5C8EF6"; /* blue    */
static char termcol13[] = "#FF466A"; /* magenta */
static char termcol14[] = "#10D0E8"; /* cyan    */
static char termcol15[] = "#F0F0F0"; /* white   */
/* termcolor array -----------------------------*/
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
/* colorscheme array ---------------------------*/
static char *colors[][3] = {
  /*                 fg           bg           border   */
  [SchemeNorm]   = { normfgcolor, normbgcolor, normbordercolor },
  [SchemeSel]    = { selfgcolor,  selbgcolor,  selbordercolor  },
  [SchemeTitle]  = { normfgcolor, normbgcolor, normbordercolor },
};
/* scratchpads =======================================================================*/
typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "80x25", NULL };
const char *spcmd2[] = {"st", "-n", "spcalc", "-g", "80x15", "-e", "calc", NULL };
const char *spcmd3[] = {"st", "-n", "sphelp", "-g", "80x30", "-e", "tutorialdoc", NULL };
static Sp scratchpads[] = {
	{"spterm",       spcmd1},
	{"spcalc",       spcmd2},
	{"sphelp",       spcmd3},
};
/* tagging ===========================================================================*/
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
/* floating rules ====================================================================*/
static const Rule rules[] = {
	/* class      instance     title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,        NULL,       0,            0,           -1 },
	{ NULL,       "spterm",    NULL,       SPTAG(0),     1,           -1 },
	{ NULL,       "spcalc",    NULL,       SPTAG(1),     1,           -1 },
	{ NULL,       "sphelp",    NULL,       SPTAG(2),     1,           -1 },
};
/* layouts ===========================================================================*/
static const float mfact = 0.5;       /* factor of master area size [0.05..0.95]      */
static const int nmaster = 1;         /* number of clients in master area             */
static const int resizehints = 0;     /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0;  /* 1 will force focus on the fullscreen window  */
#define FORCE_VSPLIT 1                 /* nrowgrid: force clients to split vertically */
#include "vanitygaps.c"
static const Layout layouts[] = {
	{ "[=]",      tile    },
	{ "[M]",      monocle },
	{ "[B]",      bstack  },
	{  NULL,      NULL    },
};
/* key definitions ===================================================================*/
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask,              KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
/* commands ===================================================================*/
static const char *termcmd[]  = {"st", NULL};
static const char *dmenucmd[] = {"dmenu_run", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL};
#include "movestack.c"
/* keyboard shortcuts ---------------------------------------------------------*/
static const Key keys[] = {
	/* modifier             key              function        argument            */
	/* terminal ===========|================|===============|====================*/
	{ MODKEY,               XK_Return,       spawn,          {.v = termcmd } },
	{ MODKEY,               XK_u,            togglescratch,  {.ui = 0 } },
	{ MODKEY,               XK_a,            togglescratch,  {.ui = 1 } },
	{ MODKEY,               XK_d,            spawn,          {.v = dmenucmd } },
	{ MODKEY,               XK_q,            killclient,     {0} },
	{ MODKEY|Mod1Mask,      XK_q,            quit,           {1} },
  { MODKEY|ShiftMask,     XK_q,            spawn,          SHCMD("pkill -u $USER") },
	/* stack position -----|----------------|---------------|--------------------*/
	{ MODKEY|Mod1Mask,      XK_Return,       zoom,           {0} },
	{ MODKEY,               XK_j,            focusstack,     {.i = +1 } },
	{ MODKEY,               XK_k,            focusstack,     {.i = -1 } },
	{ MODKEY|Mod1Mask,      XK_j,            movestack,      {.i = +1 } },
	{ MODKEY|Mod1Mask,      XK_k,            movestack,      {.i = -1 } },
	{ MODKEY,               XK_h,            setmfact,       {.f = -0.05} },
	{ MODKEY,               XK_l,            setmfact,       {.f = +0.05} },
	/* layout =============|================|===============|====================*/
	{ MODKEY,               XK_Tab,          view,           {0} },
	{ MODKEY,               XK_f,            fullscreen,     {0} },
	{ MODKEY,               XK_b,            togglebar,      {0} },
	{ MODKEY,               XK_space,        setlayout,      {0} },
	{ MODKEY|Mod1Mask,      XK_space,        togglefloating, {0} },
	{ MODKEY|Mod1Mask,      XK_comma,        cyclelayout,    {.i = -1 } },
	{ MODKEY|Mod1Mask,      XK_period,       cyclelayout,    {.i = +1 } },
	/* gaps ---------------|----------------|---------------|--------------------*/
	{ MODKEY,               XK_0,            togglegaps,     {0} },
	{ MODKEY|ShiftMask,     XK_0,            defaultgaps,    {0} },
	{ MODKEY|ShiftMask,     XK_j,            incrgaps,       {.i = +5 } },
	{ MODKEY|ShiftMask,     XK_k,            incrgaps,       {.i = -5 } },
	/* function keys ======|================|===============|====================*/
	{ MODKEY,               XK_F1,           togglescratch,  {.ui = 2 } },
	{ MODKEY,               XK_F2,           spawn,          {.v = (const char*[]){ "tutorialvids", NULL } } },
	{ MODKEY,               XK_F3,           spawn,          {.v = (const char*[]){ "mounter", NULL } } },
	{ MODKEY,               XK_F4,           spawn,          {.v = (const char*[]){ "unmounter", NULL } } },
	{ MODKEY,               XK_F5,           xrdb,           {.v = NULL } },
	{ MODKEY,               XK_F6,           spawn,          SHCMD("pkill -u $USER") },
	{ MODKEY,               XK_F7,           spawn,          {.v = (const char*[]){ "displayselect", NULL } } },
	{ MODKEY,               XK_F8,           spawn,          SHCMD("slock systemctl hibernate -i") },
	{ MODKEY,               XK_F9,           spawn,          {.v = (const char*[]){ TERMINAL, "-e", "sudo", "nmtui", NULL } } },
	{ MODKEY,               XK_F10,          spawn,          {.v = (const char*[]){ "mailsync", NULL } } },
	{ MODKEY,               XK_F11,          spawn,          {.v = (const char*[]){ "vpn", "toggle", NULL } } },
	{ MODKEY,               XK_F12,          spawn,          {.v = (const char*[]){ "slock", NULL } } },
	/* programs ===========|================|===============|====================*/
	{ MODKEY,               XK_r,            spawn,          SHCMD(TERMINAL " -e vifm ~/") },
	{ MODKEY,               XK_i,            spawn,          {.v = (const char*[]){ TERMINAL, "-e", "btop", NULL } } },
	{ MODKEY,               XK_w,            spawn,          {.v = (const char*[]){ BROWSER, NULL } } },
	{ MODKEY,               XK_grave,        spawn,          {.v = (const char*[]){ "dmenuunicode", NULL } } },
	{ MODKEY,               XK_backslash,    spawn,          {.v = (const char*[]){ "passmenu", NULL } } },
	{ MODKEY,               XK_BackSpace,    spawn,          {.v = (const char*[]){ "sysact", NULL } } },
	/* media ==============|================|===============|====================*/
	{ MODKEY,               XK_c,            spawn,          {.v = (const char*[]){ TERMINAL, "-e", "profanity", NULL } } },
	{ MODKEY,               XK_n,            spawn,          SHCMD(TERMINAL " -e newsboat") },
	{ MODKEY,               XK_e,            spawn,          SHCMD(TERMINAL " -e neomutt ; rmdir ~/.abook") },
	{ MODKEY|Mod1Mask,      XK_e,            spawn,          SHCMD(TERMINAL " -e abook -C ~/.config/abook/abookrc --datafile ~/.config/abook/addressbook") },
	/* recording ----------|----------------|---------------|--------------------*/
	{ 0,                    XK_Print,        spawn,          SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png") },
	{ ShiftMask,            XK_Print,        spawn,          {.v = (const char*[]){ "maimpick", NULL } } },
	{ MODKEY,               XK_Print,        spawn,          {.v = (const char*[]){ "dmenurecord", NULL } } },
	/* music --------------|----------------|---------------|--------------------*/
	{ MODKEY|Mod1Mask,      XK_a,            spawn,          SHCMD(TERMINAL " -e pulsemixer; sb-volume refresh") },
	{ MODKEY|Mod1Mask,      XK_m,            spawn,          {.v = (const char*[]){ TERMINAL, "-e", "ncmpcpp", NULL } } },
	{ MODKEY,               XK_m,            spawn,          SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; sb-volume refresh") },
	{ MODKEY,               XK_minus,        spawn,          SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@  5%-; sb-volume refresh") },
	{ MODKEY,               XK_equal,        spawn,          SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@  5%+; sb-volume refresh") },
	{ MODKEY|Mod1Mask,      XK_minus,        spawn,          SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%-; sb-volume refresh") },
	{ MODKEY|Mod1Mask,      XK_equal,        spawn,          SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%+; sb-volume refresh") },
	{ MODKEY,               XK_p,            spawn,          SHCMD("mpc toggle;   sb-music refresh") },
	{ MODKEY,               XK_slash,        spawn,          SHCMD("mpc clear;    sb-music refresh") },
	{ MODKEY,               XK_comma,        spawn,          SHCMD("mpc prev;     sb-music refresh") },
	{ MODKEY,               XK_period,       spawn,          SHCMD("mpc next;     sb-music refresh") },
	{ MODKEY,               XK_bracketleft,  spawn,          SHCMD("mpc seek -10; sb-music refresh") },
	{ MODKEY,               XK_bracketright, spawn,          SHCMD("mpc seek +10; sb-music refresh") },
	{ MODKEY|Mod1Mask,      XK_bracketleft,  spawn,          SHCMD("mpc seek -60; sb-music refresh") },
	{ MODKEY|Mod1Mask,      XK_bracketright, spawn,          SHCMD("mpc seek +60; sb-music refresh") },
	/* tags ===============|================|===============|====================*/
	TAGKEYS(                XK_1,                            0)
	TAGKEYS(                XK_2,                            1)
	TAGKEYS(                XK_3,                            2)
	TAGKEYS(                XK_4,                            3)
	TAGKEYS(                XK_5,                            4)
	TAGKEYS(                XK_6,                            5)
	TAGKEYS(                XK_7,                            6)
	TAGKEYS(                XK_8,                            7)
	TAGKEYS(                XK_9,                            8)
};
/* button definitions ==========================================================================*/
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
