#include <stdio.h>

int main()
{
    int choice;

    // 5 Movies
    char movies[5][30] =
    {
        "Avatar 2",
        "Room No. 106",
        "Toy Story 5",
        "Minions",
        "Spider-Man"
    };

    // 2 Showtimes for each movie
    char showtimes[5][2][20] =
    {
        {"10:00 AM", "07:00 PM"},
        {"11:00 AM", "08:00 PM"},
        {"12:00 PM", "09:00 PM"},
        {"01:00 PM", "10:00 PM"},
        {"02:00 PM", "11:00 PM"}
    };

    // 5 Movies × 2 Showtimes × 5 Rows × 10 Seats
    char seats[5][2][5][10];

    // Initialize all seats as available
    for(int m = 0; m < 5; m++)
    {
        for(int s = 0; s < 2; s++)
        {
            for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    seats[m][s][i][j] = '.';
                }
            }
        }
    }

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
            {
                printf("\n========== MOVIES & SHOWTIMES ==========\n");

                for(int i = 0; i < 5; i++)
                {
                    printf("\nMovie %d: %s\n", i + 1, movies[i]);

                    for(int j = 0; j < 2; j++)
                    {
                        printf("   Showtime %d: %s\n", j + 1, showtimes[i][j]);
                    }
                }

                break;
            }

            case 2:
            {
                int movieChoice, showChoice;

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

                printf("\nSelect Showtime:\n");

                for(int i = 0; i < 2; i++)
                {
                    printf("%d. %s\n", i + 1, showtimes[movieChoice - 1][i]);
                }

                printf("Enter Showtime Number: ");
                scanf("%d", &showChoice);

                if(showChoice < 1 || showChoice > 2)
                {
                    printf("Invalid showtime!\n");
                    break;
                }

                printf("\n========== SEAT MAP ==========\n\n");

                printf("      ");

                for(int j = 1; j <= 10; j++)
                {
                    printf("%2d ", j);
                }

                printf("\n");

                char rowNames[5] = {'A', 'B', 'C', 'D', 'E'};

                for(int i = 0; i < 5; i++)
                {
                    printf("%c     ", rowNames[i]);

                    for(int j = 0; j < 10; j++)
                    {
                        printf("%c  ", seats[movieChoice - 1][showChoice - 1][i][j]);
                    }

                    if(i == 0 || i == 1)
                        printf(" Regular (Rs.500)");
                    else if(i == 2 || i == 3)
                        printf(" Premium (Rs.750)");
                    else
                        printf(" VIP (Rs.1000)");

                    printf("\n");
                }

                break;
            }

            case 3:
                printf("Book a Seat selected.\n");
                break;

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
