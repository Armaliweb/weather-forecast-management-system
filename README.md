# weather-forecast-management-system
C-based Weather Forecast Management System with user authentication. Includes features for sign-up/login, data entry, update/delete, and weather statistics (temperature, humidity, UV index, wind speed).
# Weather Forecast Management System

A C project that manages weather forecast data with integrated user authentication.  
The program allows users to **sign up, log in, update information, and manage forecast records**.

## Features
- User registration and login (with secret question for recovery).
- Add, update, delete, and display forecast data.
- Weather attributes: Day, Month, Year, Temperature, Max UV Index, Humidity, Wind Speed.
- Calculate average temperature over a given period.
- Simple file-based storage (`forecast.txt`).

## Technologies
- Language: **C**
- File handling for persistent data storage
- Modular functions for login, sign-up, data handling

## Project Structure
- `login()`: Handles user login and authentication
- `sign_up()`: Registers new users
- `add_forecast_data()`: Add forecast records
- `display_forecast()`: Show forecast entries
- `Update_delete_forecast_data()`: Update or delete records
- `temp_average()`: Calculate average temperature
- `main()`: Entry point, links all features

## How to Run
1. Compile the project:
   ```bash
   gcc project.c -o forecast

