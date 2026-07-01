# Real Estate Management System

A Windows console application written in C for managing real estate listings. The app supports user registration, login, property entry, property removal, reports, and admin-only summary views.

## Features

- Sign up and sign in with user/admin roles.
- Add residential, office, and land properties for sale or rent.
- Archive removed properties instead of deleting their records.
- Filter reports by area, price, meterage, building age, and room count.
- Admin reports for users, active/archived listings, and total values.
- Plain-text data files are created automatically on first run.

## Requirements

- Windows
- A C compiler that supports Windows headers, such as MinGW-w64 GCC

The program uses `conio.h` and `windows.h`, so it is intentionally Windows-oriented.

## Build

With GCC/MinGW-w64 installed and available on `PATH`:

```bat
gcc -Wall -Wextra -std=c11 -o real_estate.exe main.c
```

Or use the included build script:

```bat
build.bat
```

## Run

```bat
real_estate.exe
```

On first launch, the app creates these runtime data files if they do not exist:

- `user_info.txt`
- `sell_residential_properties.txt`
- `rent_residential_properties.txt`
- `sell_office_properties.txt`
- `rent_office_properties.txt`
- `sell_land_properties.txt`
- `rent_land_properties.txt`

These files contain local application data and are ignored by Git.

## Notes

- Admin account creation is protected by a hard-coded owner password in `main.c`. Change this before using the project for anything beyond coursework or local testing.
- Passwords and personal data are only lightly obfuscated, not securely encrypted.
- This project is a console/file-based learning project, not production real estate software.
