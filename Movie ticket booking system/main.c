
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
        printf("      MOVIE TICKET BOOKING SYSTEM\n");
        printf("=====================================\n");
        printf("1. View Showtimes\n");
        printf("2. View Seat Map\n");
        printf("3. Book a Seat\n");
        printf("4. Cancel a Booking\n");
        printf("5. Search Booking\n");
        printf("6. Revenue Report\n");
        printf("7. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nView Showtimes selected.\n");
                break;

            case 2:
                printf("\nView Seat Map selected.\n");
                break;
            case 3:
            {
                int movieChoice, showChoice;
                char row;
                int rowIndex, seatChoice;
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
                    printf("%d. %s\n", i + 1, showtimes[movieChoice - 1][i]);
                }

                printf("Enter Showtime Number: ");

                scanf("%d", &showChoice);

                if(showChoice < 1 || showChoice > 2)
                {
                    printf("Invalid showtime!\n");
                    break;
                }

                // Select Row
                printf("Enter Row (A-E): ");
                scanf(" %c", &row);

                // Convert lowercase to uppercase
                if(row >= 'a' && row <= 'e')
                {
                    row = row - 32;
                }

                rowIndex = row - 'A';

                if(rowIndex < 0 || rowIndex > 4)
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
                if(seats[movieChoice - 1][showChoice - 1][rowIndex][seatChoice - 1] == 'X')
                {
                    printf("\nSorry! This seat is already booked.\n");
                    break;
                }

                // Customer name
                printf("Enter Customer Name: ");
                scanf(" %[^\n]", customerName);

                // Calculate price according to row
                if(rowIndex == 0 || rowIndex == 1)
                {
                    price = 500;
                }
                else if(rowIndex == 2 || rowIndex == 3)
                {
                    price = 750;
                }
                else
                {
                    price = 1000;
                }

                // Book the seat
                seats[movieChoice - 1][showChoice - 1][rowIndex][seatChoice - 1] = 'X';

                printf("\n========== BOOKING SUCCESSFUL ==========\n");
                printf("Customer Name : %s\n", customerName);
                printf("Movie         : %s\n", movies[movieChoice - 1]);
                printf("Showtime      : %s\n", showtimes[movieChoice - 1][showChoice - 1]);
                printf("Row           : %c\n", row);
                printf("Seat Number   : %d\n", seatChoice);
                printf("Ticket Price  : Rs. %.2f\n", price);

                break;
            }
            case 4:
            {
                int movieChoice, showChoice, column;
                char rowChar;
                int rowIndex, columnIndex;
                int movieIndex, showtimeIndex;

                printf("\n========== CANCEL A BOOKING ==========\n");

                printf("\nSelect Movie:\n");

                for(int i = 0; i < 5; i++)
                {
                    printf("%d. %s\n", i + 1, movies[i]);
                }

                printf("Enter Movie Number (1-5): ");
                scanf("%d", &movieChoice);

                if(movieChoice < 1 || movieChoice > 5)
                {
                    printf("Invalid movie choice!\n");
                    break;
                }

                printf("\nSelect Showtime for %s\n", movies[movieChoice - 1]);

                for(int i = 0; i < 2; i++)
                {
                    printf("%d. %s\n", i + 1, showtimes[movieChoice - 1][i]);
                }

                printf("Enter Showtime Number (1-2): ");
                scanf("%d", &showChoice);

                if(showChoice < 1 || showChoice > 2)
                {
                    printf("Invalid showtime choice!\n");
                    break;
                }

                printf("Enter Row Letter (A-E): ");
                scanf(" %c", &rowChar);

                printf("Enter Seat Number (1-10): ");
                scanf("%d", &column);

                if(column < 1 || column > 10)
                {
                    printf("Invalid seat number!\n");
                    break;
                }

                if(rowChar >= 'a' && rowChar <= 'e')
                {
                    rowIndex = rowChar - 'a';
                    rowChar -= 32;
                }
                else if(rowChar >= 'A' && rowChar <= 'E')
                {
                    rowIndex = rowChar - 'A';
                }
                else
                {
                    printf("Invalid row! Enter A-E.\n");
                    break;
                }

                movieIndex = movieChoice - 1;
                showtimeIndex = showChoice - 1;
                columnIndex = column - 1;

                if(seats[movieIndex][showtimeIndex][rowIndex][columnIndex] == '.')
                {
                    printf("\nSeat %c%d is already available.\n", rowChar, column);
                }
                else
                {
                    seats[movieIndex][showtimeIndex][rowIndex][columnIndex] = '.';

                    printf("\nBooking Cancelled Successfully!\n");
                    printf("Movie    : %s\n", movies[movieIndex]);
                    printf("Showtime : %s\n", showtimes[movieIndex][showtimeIndex]);
                    printf("Seat     : %c%d\n", rowChar, column);
                }

                break;
            }

            case 5:

            {
                int movieChoice, showChoice;
                char row;
                int rowIndex, seat;

                printf("\n=====================================\n");
                printf("           SEARCH BOOKING\n");
                printf("=====================================\n");

                printf("Available Movies\n");
                printf("-------------------------------------\n");

                for(int i = 0; i < 5; i++)
                {
                    printf("%d. %-20s\n", i + 1, movies[i]);
                }

                printf("-------------------------------------\n");
                printf("Enter movie number     : ");
                scanf("%d", &movieChoice);

                if(movieChoice < 1 || movieChoice > 5)
                {
                    printf("\nInvalid movie selection!\n");
                    break;
                }

                printf("\nShowtimes for %s\n", movies[movieChoice - 1]);
                printf("-------------------------------------\n");
                printf("1. %s\n", showtimes[movieChoice - 1][0]);
                printf("2. %s\n", showtimes[movieChoice - 1][1]);
                printf("-------------------------------------\n");

                printf("Enter showtime number  : ");
                scanf("%d", &showChoice);

                if(showChoice < 1 || showChoice > 2)
                {
                    printf("\nInvalid showtime selection!\n");
                    break;
                }

                printf("Enter row (A-E)        : ");
                scanf(" %c", &row);

                // Convert lowercase to uppercase
                if(row >= 'a' && row <= 'e')
                {
                    row = row - 32;
                }

                rowIndex = row - 'A';

                if(rowIndex < 0 || rowIndex > 4)
                {
                    printf("\nInvalid row selection!\n");
                    break;
                }

                printf("Enter seat (1-10)      : ");
                scanf("%d", &seat);

                if(seat < 1 || seat > 10)
                {
                    printf("\nInvalid seat position!\n");
                    break;
                }

                printf("\n=====================================\n");

                if(seats[movieChoice - 1][showChoice - 1][rowIndex][seat - 1] == 'X')
                {
                    printf("           BOOKING FOUND\n");
                    printf("=====================================\n");
                    printf("Movie      : %s\n", movies[movieChoice - 1]);
                    printf("Showtime   : %s\n", showtimes[movieChoice - 1][showChoice - 1]);
                    printf("Row        : %c\n", row);
                    printf("Seat       : %d\n", seat);
                    printf("Status     : BOOKED\n");
                }
                else
                {
                    printf("         BOOKING NOT FOUND\n");
                    printf("=====================================\n");
                    printf("Movie      : %s\n", movies[movieChoice - 1]);
                    printf("Showtime   : %s\n", showtimes[movieChoice - 1][showChoice - 1]);
                    printf("Row        : %c\n", row);
                    printf("Seat       : %d\n", seat);
                    printf("Status     : AVAILABLE\n");
                }

                printf("=====================================\n");
                break;
            }

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
                printf("\nThank you for using the Movie Ticket Booking System!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while(choice != 7);

    return 0;
}
