//
// Created by david on 9/25/26.
//

#include <iso646.h>
#include <stdio.h>
#include <ctype.h>

double celsiusToKelvin(const double celsius) {
    return celsius + 273.15;
}
double celsiusToFahrenheit(const double celsius) {
    return celsius * 1.8 + 32;
}

double kelvinToCelsius(const double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(const double kelvin) {
    return kelvin * 1.8 - 459.67;
}

double fahrenheitToKelvin(const double fahrenheit) {
    return (fahrenheit + 459.67) / 1.8;
}

double fahrenheitToCelsius(const double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

void weatherAdvisory(double tempInCelsius) {
    if (tempInCelsius < 0) {
        printf("Temperature Category: Freezing\n");
        printf("Weather Advisory: Wear a heavy coat.\n");
    }
    if (0 <= tempInCelsius && tempInCelsius < 10) {
        printf("Temperature Category: Cold\n");
        printf("Weather Advisory: Wear a coat\n");
    }
    if (10 <= tempInCelsius && tempInCelsius < 25) {
        printf("Temperature Category: Comfortable\n");
        printf("Weather Advisory: Wear whatever you like\n");
    }
    if (25 <= tempInCelsius && tempInCelsius < 35) {
        printf("Temperature Category: Hot\n");
        printf("Weather Advisory: Stay hydrated\n");
    }
    if (35 <= tempInCelsius) {
        printf("Temperature Category: Extreme Heat\n");
        printf("Weather Advisory: Stay indoors\n");
    }
}



static void discardLine(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

static int isValidScale(const char scale) {
    return scale == 'C' || scale == 'F' || scale == 'K';
}

// Prompts until a valid scale (C, F, or K, case-insensitive) is entered. Returns 0 on EOF.
static int readScale(const char *prompt, char *out) {
    while (1) {
        printf("\n%s", prompt);
        char c;
        if (scanf(" %c", &c) != 1) {
            return 0;
        }
        discardLine();
        c = (char) toupper((unsigned char) c);
        if (isValidScale(c)) {
            *out = c;
            return 1;
        }
        printf("Invalid scale '%c'. Please enter C, F, or K.\n", c);
    }
}

static double toKelvin(const double value, const char scale) {
    if (scale == 'C') return celsiusToKelvin(value);
    if (scale == 'F') return fahrenheitToKelvin(value);
    return value;
}



int main () {
    double temperatureValue;
    char originalScale;
    char convertScale;

    while (1) {
        printf("\nEnter the temperature value: ");
        if (scanf("%lf", &temperatureValue) != 1) {
            if (feof(stdin)) {
                return 1;
            }
            printf("Invalid temperature. Please enter a number.\n");
            discardLine();
            continue;
        }
        discardLine();

        if (!readScale("Enter the original scale: (C, F, or K): ", &originalScale)) {
            return 1;
        }

        if (toKelvin(temperatureValue, originalScale) < 0) {
            printf("Temperature is below absolute zero. Please try again.\n");
            continue;
        }
        break;
    }

    if (!readScale("Enter the scale to convert to (C, F, or K): ", &convertScale)) {
        return 1;
    }

    if (originalScale == 'C') {
        if (convertScale == 'C') {
            printf("Converted Temperature: %lf %c\n", temperatureValue, convertScale);
        } else if (convertScale == 'F') {
            printf("Converted Temperature: %lf %c\n", celsiusToFahrenheit(temperatureValue), convertScale);
        } else {
            printf("Converted Temperature: %lf %c\n", celsiusToKelvin(temperatureValue), convertScale);
        }
        weatherAdvisory(temperatureValue);
    } else if (originalScale == 'F') {
        if (convertScale == 'F') {
            printf("Converted Temperature: %lf %c\n", temperatureValue, convertScale);
        } else if (convertScale == 'C') {
            printf("Converted Temperature: %lf %c\n", fahrenheitToCelsius(temperatureValue), convertScale);
        } else {
            printf("Converted Temperature: %lf %c\n", fahrenheitToKelvin(temperatureValue), convertScale);
        }
        weatherAdvisory(fahrenheitToCelsius(temperatureValue));
    } else if (originalScale == 'K') {
        if (convertScale == 'K') {
            printf("Converted Temperature: %lf %c\n", temperatureValue, convertScale);
        } else if (convertScale == 'C') {
            printf("Converted Temperature: %lf %c\n", kelvinToCelsius(temperatureValue), convertScale);
        } else {
            printf("Converted Temperature: %lf %c\n", kelvinToFahrenheit(temperatureValue), convertScale);
        }
        weatherAdvisory(kelvinToCelsius(temperatureValue));
    }
    return 0;
}
