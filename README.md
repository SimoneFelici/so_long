*This project has been created as part of the 42 curriculum by sfelici.*

# so_long

## Description

so_long is a small 2D top-down game built in C using the MiniLibX graphics library. The player navigates a tile-based map, collecting all items before reaching the exit. The map is validated at launch using a Depth First Search algorithm to ensure a valid path exists. The project covers window management, event handling, textures, sprites, and basic gameplay logic.

Bonus features include enemy patrols that move when the player moves, a kill mechanic using a flint and steel (press `E` near an enemy), explosion animations, and a live move counter displayed on screen.

## Instructions

**Dependencies**

MiniLibX requires the following packages on Linux:
```
sudo apt install libx11-dev libxext-dev
```

**Build**
```
make
```

**Run**
```
./so_long maps/map.ber
```

The map file must use the `.ber` extension and follow these rules:
- Surrounded by walls (`1`)
- Contains exactly one player (`P`), one exit (`E`), and at least one collectible (`C`)
- Optionally contains enemy patrols (`V`)
- Must have a valid path from `P` to `E` through all `C`

**Controls**

| Key | Action |
|-----|--------|
| `W` `A` `S` `D` | Move |
| `E` | Attack adjacent enemy |
| `ESC` | Quit |

## Resources

- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
