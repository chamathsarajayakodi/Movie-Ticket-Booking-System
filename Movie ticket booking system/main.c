#include <stdio.h>
#include <string.h>

char movies[5][30] =
{
    "Avatar 2",
    "Room No. 106",
    "Toy Story 5",
    "Minions",
    "Spider-Man"
};

char showtimes[5][2][20] =
{
    {"10:00 AM", "07:00 PM"},
    {"11:00 AM", "08:00 PM"},
    {"12:00 PM", "09:00 PM"},
    {"01:00 PM", "10:00 PM"},
    {"02:00 PM", "11:00 PM"}
};
char seats[5][2][5][10]=
{
};
int main()
{
    int choice;

    do
    {
        printf("\n=====================================\n");
        printf("     MOVIE TICKET BOOKING SYSTEM\n");
        printf("=====================================\n");
        printf("1. View Showtimes\n");
        printf("2. View Seat Map\n");
        printf("3. Book a Seat\n");
        printf("4. Cancel a Booking\n");
        printf("5. Search Booking\n");
        printf("6. Revenue Report\n");
        printf("7. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("View Showtimes selected.\n");
                break;

            case 2:
                printf("View Seat Map selected.\n");
                break;
            case 3:
{
    int movieChoice, showChoice;
    int rowChoice, seatChoice;
    char customerName[50];
    float price;

    printf("\n========== BOOK A SEAT ==========\n");

    // Select Movie
    printf("\nSelect Movie:\n");

    for(int i = 0; i < 5; i++)
    {
        printf("%d. %s\n", i + 1, movies[i]);
    }

    printf("Enter Movie Number: ");
    scanf("%d", &movieChoice);

    if(movieChoice < 1 || movieChoice > 5)
    {
        printf("Invalid movie!\n");
        break;
    }

    // Select Showtime
    printf("\nSelect Showtime:\n");

    for(int i = 0; i < 2; i++)
    {
        printf("%d. %s\n",
               i + 1,
               showtimes[movieChoice - 1][i]);
    }

    printf("Enter Showtime Number: ");
    scanf("%d", &showChoice);

    if(showChoice < 1 || showChoice > 2)
    {
        printf("Invalid showtime!\n");
        break;
    }

    // Select Row
    printf("\nEnter Row Number (1-5): ");
    scanf("%d", &rowChoice);

    if(rowChoice < 1 || rowChoice > 5)
    {
        printf("Invalid row!\n");
        break;
    }

    // Select Seat
    printf("Enter Seat Number (1-10): ");
    scanf("%d", &seatChoice);

    if(seatChoice < 1 || seatChoice > 10)
    {
        printf("Invalid seat number!\n");
        break;
    }

    // Check seat availability
    if(seats[movieChoice - 1]
           [showChoice - 1]
           [rowChoice - 1]
           [seatChoice - 1] == 'X')
    {
        printf("\nSorry! This seat is already booked.\n");
        break;
    }

    // Customer name
    printf("Enter Customer Name: ");
    scanf(" %[^\n]", customerName);

    // Calculate price according to row
    if(rowChoice == 1 || rowChoice == 2)
    {
        price = 500;
    }
    else if(rowChoice == 3 || rowChoice == 4)
    {
        price = 750;
    }
    else
    {
        price = 1000;
    }

    // Book the seat
    seats[movieChoice - 1]
         [showChoice - 1]
         [rowChoice - 1]
         [seatChoice - 1] = 'X';

    printf("\n========== BOOKING SUCCESSFUL ==========\n");
    printf("Customer Name : %s\n", customerName);
    printf("Movie         : %s\n", movies[movieChoice - 1]);
    printf("Showtime      : %s\n",
           showtimes[movieChoice - 1][showChoice - 1]);

    printf("Row           : %c\n", 'A' + rowChoice - 1);
    printf("Seat Number   : %d\n", seatChoice);
    printf("Ticket Price  : Rs. %.2f\n", price);

    break;
}

            case 4:
                printf("Cancel Booking selected.\n");
                break;

            case 5:
                printf("Search Booking selected.\n");
                break;

            case 6:
                printf("Revenue Report selected.\n");
                break;

            case 7:
                printf("Thank you for using the system!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 7);

    return 0;
}
