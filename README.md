# MARS - Custom DWM Configuration

Inspired by Luke Smith's LARBS, this setup focuses on efficiency, keyboard-driven workflow, and customization. Below is a brief guide to the key features and patches included in my custom build of the Dynamic Window Manager (DWM).

## Key Features

- **Keyboard-Centric Workflow**: Capslock remapped to `Escape` for easier Vim navigation.
- **Minimal & Efficient**: Designed to be lightweight and fast, with small terminal-based programs.
- **Custom Status Bar**: A colorful, functional status bar powered by dwmblocks and `status2d`.
- **Highly Customizable**: Everything from keybindings to asthetic can be modified in config files.

## Essential Keybindings

| **Application**          | **Key Binding**                      |
|--------------------------|--------------------------------------|
| **Launch Terminal**      | `Mod+Enter`                          |
| **Kill Window**          | `Mod+q`                              |
| **Toggle Fullscreen**    | `Mod+f`                              |
| **Switch Window Layout** | `Mod+Space`                          |
| **Cycle Layouts**        | `Mod+Alt+comma` / `Mod+Alt+period`   |
| **Scratchpads**          | `Mod+u` / `Mod+a`                    |

## Patched Features

| **Patch**             | **Description**                                                                    |
|-----------------------|------------------------------------------------------------------------------------|
| **XRDB**              | Reads colors from `.Xresources` at runtime, allowing dynamic theme changes.        |
| **Status2D**          | Enables colored text and shapes in the status bar for a more dynamic look.         |
| **Status2D-xrdb**     | Allows colors from `.Xresources` to be applied to the status bar, (used by pywal). |
| **StatusCMD**         | Enables interaction with status bar elements, passing mouse clicks to `dwmblocks`. |
| **Titlecolor**        | Allows independent color schemes for window titles in the status bar.              |
| **PerTag**            | Retains layout, master window factor, and bar position for each tag.               |
| **PreserveOnRestart** | Maintains window tags across DWM restarts.                                         |
| **RestartSig**        | Restart DWM with (`Mod+Shift+Q`) combination or (`kill -HUP dwmpid`) command.      |
| **Movestack**         | Enables moving windows up and down the stack.                                      |
| **CycleLayouts**      | Allows cycling through layouts using key combinations.                             |
| **Scratchpads**       | Multiple floating or tiled scratchpads for quick access to specific applications.  |
| **Fullscreen**        | Switches to fullscreen mode, hiding the status bar.                                |
| **RemoveBorder**      | Automatically removes borders when only one window is visible.                     |
| **Vanitygaps**        | Adds customizable gaps between windows for aesthetic spacing.                      |

## Installation & Customization

All keybindings and patches are managed through the `config.h` file. For more advanced configurations (like changing status bar modules), simply modify the relevant scripts located in `~/.local/bin/statusbar/`.

To recompile DWM with your custom settings, run:
```bash
sudo make clean install
```

For a full list of keybindings and additional features, refer to the `mars.mom` documentation available via `Mod+F1`.

## Patching DWM

To apply or modify patches:
1. Download the desired patch from `dwm.suckless.org/patches`.
2. Apply the patch to your DWM source with `patch -p1 < patch.diff`.
3. Modify the `config.h` file to integrate the patch.
4. Recompile DWM with `make clean install`.

## Credits
Credit goes to [Luke Smith](https://www.github.com/lukesmithxyz)'s custom configuration and the original authors of DWM.
