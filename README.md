<h1 align=center> ATLAS </h1>
<p align="center">
  <a href="https://github.com/mintRaven-05/Atlas/stargazers"><img src="https://img.shields.io/github/stars/mintRaven-05/Atlas?colorA=363a4f&colorB=b7bdf8&style=for-the-badge&logo=data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAyNTYgMjU2Ij4KPHBhdGggZD0iTTIzNS4yNCw4NC4zOGwtMjguMDYsMjMuNjgsOC41NiwzNS4zOWExMy4zNCwxMy4zNCwwLDAsMS01LjA5LDEzLjkxLDEzLjU0LDEzLjU0LDAsMCwxLTE1LC42OUwxNjQsMTM5bC0zMS42NSwxOS4wNmExMy41MSwxMy41MSwwLDAsMS0xNS0uNjksMTMuMzIsMTMuMzIsMCwwLDEtNS4xLTEzLjkxbDguNTYtMzUuMzlMOTIuNzYsODQuMzhhMTMuMzksMTMuMzksMCwwLDEsNy42Ni0yMy41OGwzNi45NC0yLjkyLDE0LjIxLTMzLjY2YTEzLjUxLDEzLjUxLDAsMCwxLDI0Ljg2LDBsMTQuMjEsMzMuNjYsMzYuOTQsMi45MmExMy4zOSwxMy4zOSwwLDAsMSw3LjY2LDIzLjU4Wk04OC4xMSwxMTEuODlhOCw4LDAsMCwwLTExLjMyLDBMMTguMzQsMTcwLjM0YTgsOCwwLDAsMCwxMS4zMiwxMS4zMmw1OC40NS01OC40NUE4LDgsMCwwLDAsODguMTEsMTExLjg5Wm0tLjUsNjEuMTlMMzQuMzQsMjI2LjM0YTgsOCwwLDAsMCwxMS4zMiwxMS4zMmw1My4yNi01My4yN2E4LDgsMCwwLDAtMTEuMzEtMTEuMzFabTczLTEtNTQuMjksNTQuMjhhOCw4LDAsMCwwLDExLjMyLDExLjMybDU0LjI4LTU0LjI4YTgsOCwwLDAsMC0xMS4zMS0xMS4zMloiIHN0eWxlPSJmaWxsOiAjQ0FEM0Y1OyIvPgo8L3N2Zz4="></a>
  <a href="https://github.com/mintRaven-05/Atlas/releases/latest"><img src="https://img.shields.io/github/v/release/mintRaven-05/Atlas?colorA=363a4f&colorB=a6da95&style=for-the-badge&logo=github&logoColor=cad3f5"></a>
  <a href="https://github.com/mintRaven-05/Atlas/issues"><img src="https://img.shields.io/github/issues/mintRaven-05/Atlas?colorA=363a4f&colorB=f5a97f&style=for-the-badge&logo=data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAyNTYgMjU2Ij4KPHBhdGggZD0iTTIxNiwzMlYxOTJhOCw4LDAsMCwxLTgsOEg3MmExNiwxNiwwLDAsMC0xNiwxNkgxOTJhOCw4LDAsMCwxLDAsMTZINDhhOCw4LDAsMCwxLTgtOFY1NkEzMiwzMiwwLDAsMSw3MiwyNEgyMDhBOCw4LDAsMCwxLDIxNiwzMloiIHN0eWxlPSJmaWxsOiAjQ0FEM0Y1OyIvPgo8L3N2Zz4="></a>
</p>

## Purpose

Atlas is a robust ELF parser implemented in C programming language. It is a comprehensive tool set for dissecting and understanding ELF binaries with a custom decoder. Designed for developers, security researchers, and anyone curious about the low-level world of program binaries.

 >[!IMPORTANT]
 >This tool is only supported by Linux-based OS and only for 64-bit architecture. This project is still under development and undergoing heavy modifications. You can put this project to watch list if you wish to use this.
 
 >[!NOTE]
>This tool is only available for parsing 64-bit binaries. Soon the 32-bit elf parser will be released.
## Installation

Copy this repository

```bash
git clone https://github.com/mintRaven-05/Atlas.git
```

Run the `install.sh` script to install the tool.

```bash
cd Atlas
chmod +x install.sh
./install.sh
```

and this will add Atlas to `/usr/bin` path.

## Usage

You can use the help screen to list the flags and commands that you can use. To show the help screen type the following command over the terminal.

```bash
atlas --help
```

To check the current version of the tool you can use

```bash
atlas --version
```

Further usage is explained in the help screen of the tool.

## Demo Screenshot

<p align=center>
  <img src = "https://github.com/user-attachments/assets/d3d8ef89-9a81-4530-8a22-68d5c8776096">
</p>

![240712_16h17m53s_screenshot](https://github.com/user-attachments/assets/12f00ae7-ce14-4d03-a59c-87ca987ea11f)

## Uninstallation

Once installed it make a copy of the repository in the home directory inside a hidden folder. The folder is named `.Atlas`. Now you need to navigate into that folder and run the uninstaller. Run the following commands

```bash
cd .Atlas
./uninstall.sh
```

<p align="center">Copyright &copy; 2024 <a href="https://github.com/mintRaven-05" target="_blank">Debjeet Banerjee</a>
<p align="center"><a href="https://github.com/mintRaven-05/Atlas/blob/main/LICENSE"><img src="https://img.shields.io/static/v1.svg?style=for-the-badge&label=License&message=BSD-3-clause&logoColor=d9e0ee&colorA=363a4f&colorB=b7bdf8"/></a></p>
