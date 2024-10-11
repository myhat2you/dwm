# MARS User Guide
*Inspired by Luke Smith's LARBS*

## Zathura Keybindings

| Keys               | Actions                                   |
|--------------------|-------------------------------------------|
| h/j/k/l            | Use Vim keys to navigate the document.    |
| 1/2/3/..           | Jump to Nth slide.                        |
| shift+g            | Jump to last slide.                       |
| g                  | Jump to first slide.                      |
| q                  | Quit the document.                        |
| Mod + F1           | Toggle viewing this document.             |

## Basic Goals and Principles of This System:
- **Naturalness** — Remove the border between mind and matter: 
everything important should be keybound.
- **Economy** — Programs should all be simple, 
lightweight, and highly extensible.
- **Keyboard** — All terminal programs 
(and other programs) use Vim keys when possible.
- **Decentralized** — This system is a web of easily
easily customizable and replacable programs.

---

## General Keyboard Changes
- **Capslock**: Now functions as Escape/Mod key.
- **Menu Button**: Acts as another Super/Mod key.
To change these, modify ~/.local/bin/tools/remaps.

## The Status Bar
- **Left side**: Displays the current workspace/tags.
- **Right side**: Shows system stats (date, volume, etc.).

The dwmblocks program runs the status bar, 
which you can customize its source code ~/.local/src/dwmblocks/.  
The scripts used by dwmblocks are in ~/.local/bin/statusbar/.

## HiDPI and 4K Displays
If the interface appears too small, use the command: 
`xrandr --dpi <value>.`
To make it permanent, edit ~/.xprofile.

---

# Key Bindings

## Basic

| Keys                    | Actions                              |
|-------------------------|--------------------------------------|
| Mod + Enter             | Open terminal (default is st).       |
| Mod + u                 | Open floating terminal.              |
| Mod + a                 | Open floating calculator.            |
| Mod + d                 | Launch dmenu to search for programs. |
| Mod + q                 | Kill a window.                       |
| Mod + Alt + q           | Refresh Window Manager.              |
| Mod + Shift + q         | Quit Window Manager.                 |

---

## Workspaces/Tags

| Keys                    | Actions                              |
|-------------------------|--------------------------------------|
| Mod + (Number)          | Switch to that tag.                  |
| Mod + Shift + (Number)  | Send a window to tag.                |

## Gaps

| Keys                    | Actions                              |
|-------------------------|--------------------------------------|
| Mod + 0                 | Toggle gaps.                         |
| Mod + Shift + 0         | Restore default gaps.                |
| Mod + Shift + j/k       | Resize gaps.                         |

---

## Stack Management

| Keys               | Actions                                   |
|--------------------|-------------------------------------------|
| Mod + Alt + Enter  | Toggle the master window.                 |
| Mod + h/l          | Adjust master window width.               |
| Mod + j/k          | Cycle through windows in the stack.       |
| Mod + Alt + j/k    | Move stack position of the window.        |

## Window Layouts

| Keys               | Actions                                   |
|--------------------|-------------------------------------------|
| Mod + Tab          | Switch to previous workspace.             |
| Mod + f            | Toggle fullscreen.                        |
| Mod + b            | Toggle statusbar.                         |
| Mod + Space        | Toggle layouts.                           |
| Mod + Alt + Space  | Float a window.                           |
| Mod + Alt + comma  | Cycle layouts forward.                    |
| Mod + Alt + period | Cycle layouts backward.                   |

---

## System

| Keys            | Actions                                      |
|-----------------|----------------------------------------------|
| Mod + F1        | Open this guide.                             |
| Mod + F2        | Open tutorial videos menu.                   |
| Mod + F3        | Mount Device.                                |
| Mod + F4        | Unmount Device.                              |
| Mod + F5        | Refresh DWM.                                 |
| Mod + F6        | Restart DWM.                                 |
| Mod + F7        | Select Display.                              |
| Mod + F8        | Hibernate.                                   |
| Mod + F9        | Network Manager.                             |
| Mod + F10       | Sync Mail.                                   |
| Mod + F11       | VPN Toggle.                                  |
| Mod + F12       | Lock screen.                                 |

---

## Programs

| Keys            | Actions                                      |
|-----------------|----------------------------------------------|
| Mod + r         | Launch vifm (file manager).                  |
| Mod + i         | Launch btop (system monitor).                |
| Mod + w         | Launch web browser (default: LibreWolf).     |
| Mod + e         | Opens NeoMutt: terminal-based email client.  |
| Mod + Alt + e   | Opens NeoMutt address book.                  |
| Mod + c         | Opens Profanity: terminal-based chat client. |
| Mod + n         | Opens RSS feed reader, newsboat.             |
| Mod + Grave     | Select an emoji to copy to the clipboard.    |
| Mod + Backslash | Opens passmenu: dmenu password manager.      |
| Mod + Backspace | Select power/display actions menu.           |

---

## Media and Audio

| Keys                 | Actions                                 |
|----------------------|-----------------------------------------|
| Mod + Alt + a        | Open pulsemixer (audio control).        |
| Mod + Alt + m        | Open ncmpcpp (music player).            |
| Mod + m              | Toggle mute.                            |
| Mod + p              | Toggle pause.                           |
| Mod + plus/minus     | Adjust volume.                          |
| Mod + comma/period   | Cycle song.                             |
| Mod + Forwardslash   | Clear playlist.                         |
| Mod + left bracket   | Rewind song by 5 seconds.               |
| Mod + right bracket  | Forward song by 5 seconds.              |

## Screenshots and Recording

| Keys                 | Actions                                 |
|----------------------|-----------------------------------------|
| PrintScreen          | Take a screenshot.                      |
| Shift + PrintScreen  | Select an area to screenshot.           |
| Mod + PrintScreen    | Choose audio/video recording options.   |

---

## Configuration
- **Dotfiles**: Found in ~/.config/.
- **Suckless programs**: Configure source code in ~/.local/src/. 
Modify config.h and run `sudo make install` to recompile.

## FAQs
- **Q: What if I forget a keybinding?**  
  A: Press Mod + F1 to show this document.

- **Q: Where can I find the terminal documentation?**  
  A: Press Mod + F2 to access terminal documentation.

- **Q: How can I reset the layout?**  
  A: Use Mod + Shift + 0 to reset tiling gaps.
  A: Use Mod + Alt + q to reset the window manager.
  
- **Q: How do I customize keybindings?**  
  A: Modify the configuration files located in ~/.config/.

---

## Conclusion
MARS is designed for simplicity and flexibility. 
Customize your keybindings to make it your own.  

## Important Links
Below are the links to my github and to the OC.

## Download Links
- [MARS Auto Ricing Script](https://github.com/myhat2you/mars)
- [Custom DWM Window Manager](https://github.com/myhat2you/dwm)
- [Fork of Luke's Mutt-Wizard](https://github.com/myhat2you/mutt-wizard)

## References to Luke Smith
- [Luke Smith's GitHub](https://github.com/LukeSmithxyz)
- [Luke Smith's Donation Page](https://lukesmith.xyz/donate)

