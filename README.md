# My dwm build
Keyboard shortcuts and feature details can be found in [mars.mom](mars.mom) or through the <kbd>super-F1</kbd> shortcut.

Inspired by [lukesmith](https://github.com/lukesmithxyz/dwm)'s version of dwm.

## Patches and features
- [cyclelayouts](https://dwm.suckless.org/patches/cyclelayouts/)
Cycles through all avaiable layouts using <kbd>super-alt-comma/period</kbd>.
- [fakefullscreen](https://dwm.suckless.org/patches/fakefullscreen/):
Allows clients to fullscreen into the space provided to them.
- [fullscreen](https://dwm.suckless.org/patches/fullscreen/):
Applies the monocle layout with the focused client on top and hides the bar <kbd>super-F</kbd>.
- [movestack](https://dwm.suckless.org/patches/movestack/):
Move windows up the stack manually <kbd>super-alt-J/K</kbd>.
- [pertag](https://dwm.suckless.org/patches/pertag/):
Enables one layout per tag in contrast of one layout for all tags.
- [preserveonrestart](https://dwm.suckless.org/patches/preserveonrestart/):
preserves clients on old tags when dwm is restarted.
- [removeborder](https://dwm.suckless.org/patches/removeborder/):
Remove the border when there is only one window visible.
- [restartsig](https://dwm.suckless.org/patches/restartsig/):
Restart DWM with <kbd>kill -HUP dwmpid</kbd> or by <kbd>super-alt+Q</kbd>.
- [scratchpads](https://dwm.suckless.org/patches/scratchpads/):
Enables multiple scratchpads, each with one asigned window <kbd>super-U/A</kbd>.
- [status2d](https://dwm.suckless.org/patches/status2d/):
Allows colors and rectangle drawing in your DWM status bar.
- [status2d-xrdb](https://dwm.suckless.org/patches/status2d/):
Allows use of terminal colors from xrdb for programs like pywal.
- [statuscmd](https://dwm.suckless.org/patches/statuscmd/):
Compatibility patch for [dwmblocks](https://github.com/myhat2you/dwmblocks).
- [vanitygaps](https://dwm.suckless.org/patches/vanitygaps/):
Allows Gaps across all layouts <kbd>super-shift-J/K</kbd>, <kbd>super-0</kbd> and <kbd>super-shift-0</kbd>
- [xrdb](https://dwm.suckless.org/patches/xrdb/):
Allows dwm to read colors from xrdb (.Xresources). Required by status2d for pywal.
