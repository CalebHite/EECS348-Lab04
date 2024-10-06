#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
void categorize_temperature(float celsius);

int main() {
    float temperature, converted_temp;
    int input_scale, target_scale;

    while (1) {
        printf("Enter the temperature (negative value to exit): ");
        scanf("%f", &temperature);
        if (temperature < 0) {
            printf("Exiting...\n");
            break;
        }

        // Prompt user to choose the input scale
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &input_scale);

        // Prompt user to choose the conversion target scale
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &target_scale);

        // Input validation
        if (input_scale < 1 || input_scale > 3 || target_scale < 1 || target_scale > 3) {
            printf("Invalid conversion choice. Please try again.\n");
            continue;
        }

        // Perform conversion based on user's choices
        if (input_scale == 1 && target_scale == 2) {
            converted_temp = celsius_to_fahrenheit(temperature);
        } else if (input_scale == 1 && target_scale == 3) {
            converted_temp = celsius_to_kelvin(temperature);
        } else if (input_scale == 2 && target_scale == 1) {
            converted_temp = fahrenheit_to_celsius(temperature);
        } else if (input_scale == 2 && target_scale == 3) {
            converted_temp = fahrenheit_to_kelvin(temperature);
        } else if (input_scale == 3 && target_scale == 1) {
            converted_temp = kelvin_to_celsius(temperature);
        } else if (input_scale == 3 && target_scale == 2) {
            converted_temp = kelvin_to_fahrenheit(temperature);
        } else {
            printf("No conversion needed (same scale).\n");
            continue;
        }

        // Output the converted temperature
        if (target_scale == 1) {
            printf("Converted temperature: %.2f°C\n", converted_temp);
        } else if (target_scale == 2) {
            printf("Converted temperature: %.2f°F\n", converted_temp);
        } else {
            printf("Converted temperature: %.2fK\n", converted_temp);
        }

        // Categorize the temperature based on Celsius value
        if (target_scale == 1) {
            categorize_temperature(converted_temp);
        } else if (target_scale == 2) {
            categorize_temperature(fahrenheit_to_celsius(converted_temp));
        } else {
            categorize_temperature(kelvin_to_celsius(converted_temp));
        }
    }

    return 0;
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    if (kelvin < 0) {
        printf("Invalid temperature: Kelvin cannot be negative.\n");
        exit(1);
    }
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Stay warm, it's freezing.\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius >= 25 && celsius <= 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated, it's getting warm.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors, avoid extreme heat.\n");
    }
}
