# My_Sokoban

My_sokoban is a reproduction of the famous game "Sokoban" with the ncurses library. This project has been made at Epitech Technology in C.

## Getting Started

### Installation

This project uses the ncurses library. You can install it with the comment line below:
```bash
# Ubuntu
sudo apt-get install libncurses5-dev libncursesw5-dev
# Fedora
sudo dnf install ncurses-devel
```

### Build

To build my_sokoban:
```bash
make (re)
```

## Usage

### Run
Below you can see how to run my_sokoban.
```bash
./my_sokoban map.txt
```

### Maps
This project works with maps and you can create your own maps.
Here's an example:
```txt
############
#        O #
#      P ###
#          #
#######    #
# O  ##    #
#    ##    #
#          #
#       XX #
#       #  #
############
```
- 'P': Spawn player.
- 'O': Targets.
- 'X': Boxes.
- '#': Walls.

### Game

Here's the keys to play:
  - space_bar: Restart the game.
  - arrow_up: Move up.
  - arrow_down: Move down.
  - arrow_left: Move left.
  - arrow_right: Move right.

## How to play

### Rules

The objectif is to place all boxes on all targets without block one of them.

A boxe is blocked when you cannot move it anymore.

The game is loose when one of boxes is blocked.

The game is win when all boxes are on all targets.

## Our Team :heart:

Developers
| [<img src="https://github.com/lennyvong.png?size=85" width=85><br><sub>[Lenny Vongphouthone]</sub>](https://github.com/lennyvong)
| :---: |

<h2 align=center>
Socials Networks
</h2>

<p align='center'>
    <a href="https://www.linkedin.com/in/lenny-vongphouthone/">
        <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white">
    </a>
    <a href="https://www.instagram.com/lennyvong/">
        <img src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white">
    </a>
</p>
