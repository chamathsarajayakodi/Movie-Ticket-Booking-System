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

           case 4:
            {
                int movieChoice, showChoice, column;
                char rowChar;
                int rowIndex, columnIndex;
                int movieIndex, showtimeIndex;

                printf("\n========== CANCEL A BOOKING ==========\n");

                // Step 1: Select Movie
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

                // Step 2: Select Showtime
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

                // Step 3: Seat
                printf("Enter Row Letter (A-E): ");
                scanf(" %c", &rowChar);

                printf("Enter Seat Number (1-10): ");
                scanf("%d", &column);

                if(column < 1 || column > 10)
                {
                    printf("Invalid seat number!\n");
                    break;
                }

                // Convert row letter to index
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

                // Check booking
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
