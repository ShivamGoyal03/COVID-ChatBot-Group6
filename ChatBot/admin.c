/* COVID 19 CHATBOT
   NCU-UAG COLLABORATIVE C PROJECT
   GROUP: 6
   COPYRIGHT © GROUP 6
*/

#include <stdio.h>
#include <string.h> // For strcmp()

void adminRegistration(){
    
    char username[8], getUsername[8], getPin[4]; int pin;
    FILE *fptr; // File pointer

    // Opening the txt file having login data
    fptr = fopen("loginData.txt", "a+");

    if (fptr == NULL){
        printf("Error");    // Printing error if file does not exists
    }
    else{
    adminRegister:
        printf("Enter 8 digit userID: ");   // Requesting for a uniform 8 digit userId for registration
        scanf("%s", username);

        printf("Enter a 4 digit login PIN: ");  // Requesting a uniform 4 digit PIN
        scanf("%d", &pin);

        fscanf(fptr, "%s %s", getUsername, getPin);

        if ((strcmp(username, getUsername) == 0)){
            printf("Username already taken. Please try again.");    // Printing an error in case the user ID is already taken
            goto adminRegister;
        }

        else{
            fprintf(fptr, "%s %d\n", username, pin);    // Dumping all fetched details into "loginData.txt" file
            printf("Admin added succesfully!!!");
        }
    }   
    fclose(fptr);
}

// Designing the main menu of the admin portal
void adminMainMenu(){

    int userChoice;
    printf("\n=====MAIN MENU=====\n\n1. Add a new admin\n\nYour choice: ");
    scanf("%d", &userChoice);

    if (userChoice == 1){
        printf("\n=====NEW ADMIN REGISTRATION=====\n\n");
        adminRegistration();
    }
}

void adminPortal(){

    char userID[8], getUID[8], getPin[4], pin[4]; int flag = 0;
    FILE *fptr; // File pointer

    fptr = fopen("loginData.txt", "a+");
    fscanf(fptr, "%s %s", getUID, getPin);    // Reading userID and password from the file
adminLogin:
    printf("\n=====ADMIN PORTAL LOGIN=====\n\n");
    printf("Enter userID: "); // Requesting for userID from the user
    scanf("%s", userID);

    printf("Enter PIN: "); // Requesting for the PIN from the user
    scanf("%s", pin);

    if ((strcmp(userID, getUID) == 0 && (strcmp(pin, getPin)) == 0)){
        printf("Login succesful!!!");
        adminMainMenu();
    }

    // A user has maximum of 3 attempts to login.
    // In case the user reaches maximum attempts,
    // the loop breaks and user will have to run 
    // the bot again.

    else{
        flag += 1;
        while (flag < 3){
            printf("Incorrect input. Please try again.\n\n");
            goto adminLogin;
        }
        printf("Maximum attempts reached. Please try again later.");
    }
}