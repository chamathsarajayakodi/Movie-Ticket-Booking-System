
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
                printf("View Showtimes selected.\n");
                break;

            case 2:
                printf("View Seat Map selected.\n");
                break;

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
            {
                int movieChoice, showChoice;
                int totalTickets = 0;
                float totalRevenue = 0;

                printf("\n========== REVENUE REPORT ==========\n");

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

                // Count booked seats
                for(int row = 0; row < 5; row++)
                {
                    for(int seat = 0; seat < 10; seat++)
                    {
                        if(seats[movieChoice - 1]
                               [showChoice - 1]
                               [row][seat] == 'X')
                        {
                            totalTickets++;

                            // Calculate price according to seat tier
                            if(row == 0 || row == 1)
                            {
                                totalRevenue += 500;
                            }
                            else if(row == 2 || row == 3)
                            {
                                totalRevenue += 750;
                            }
                            else
                            {
                                totalRevenue += 1000;
                            }
                        }
                    }
                }

                // Display Revenue Report
                printf("\n========== REVENUE REPORT ==========\n");
                printf("Movie         : %s\n",
                       movies[movieChoice - 1]);

                printf("Showtime      : %s\n",
                       showtimes[movieChoice - 1][showChoice - 1]);

                printf("Tickets Sold  : %d\n", totalTickets);
                printf("Total Revenue : Rs. %.2f\n", totalRevenue);

                break;
            }

            case 7:
                printf("Thank you for using the system!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 7);

    return 0;
}
