#include <stdio.h>

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
                printf("Book a Seat selected.\n");
                break;

           case 4:
            {
                int movieChoice, showChoice, column;
                char rowChar;
                int rowIndex, columnIndex;
                char movies[5][30];
                char showtimes[5][2][20];
                char seats[5][2][5][10];


                printf("\n========== CANCEL A BOOKING ==========\n");

                // Step 1: Select Movie
                printf("\nSelect Movie:\n");
                for(int i = 0; i < 5; i++)
                {
                    printf("  %d. %s\n", i + 1, movies[i]);
                }
                printf("Enter Movie Number (1-5): ");
                if(scanf("%d", &movieChoice) != 1 || movieChoice < 1 || movieChoice > 5)
                {
                    printf("Invalid movie choice!\n");
                    break;
                }

                // Step 2: Select Showtime
                printf("\nSelect Showtime for %s:\n", movies[movieChoice - 1]);
                for(int i = 0; i < 2; i++)
                {
                    printf("  %d. %s\n", i + 1, showtimes[movieChoice - 1][i]);
                }
                printf("Enter Showtime Number (1-2): ");
                if(scanf("%d", &showChoice) != 1 || showChoice < 1 || showChoice > 2)
                {
                    printf("Invalid showtime choice!\n");
                    break;
                }

                // Step 3: Input Seat Details
                printf("\nEnter Row Letter (A-E): ");
                scanf(" %c", &rowChar);

                printf("Enter Seat Number (1-10): ");
                if(scanf("%d", &column) != 1 || column < 1 || column > 10)
                {
                    printf("Invalid seat number! Must be between 1 and 10.\n");
                    break;
                }

                // Convert row letter (A-E or a-e) to 0-4 array index
                if (rowChar >= 'a' && rowChar <= 'e')
                {
                    rowIndex = rowChar - 'a';
                    rowChar = rowChar - 32; // Convert to uppercase for output
                }
                else if (rowChar >= 'A' && rowChar <= 'E')
                {
                    rowIndex = rowChar - 'A';
                }
                else
                {
                    printf("Invalid Row! Please enter a letter between A and E.\n");
                    break;
                }

                // Step 4: Map user choices to array indices
                int movieIndex = movieChoice - 1;
                int showtimeIndex = showChoice - 1;
                columnIndex = column - 1;

                // Step 5: Check status and cancel booking
                if (seats[movieIndex][showtimeIndex][rowIndex][columnIndex] == '.')
                {
                    printf("\n[Notice] Seat %c%d for \"%s\" (%s) is not currently booked.\n",
                           rowChar, column, movies[movieIndex], showtimes[movieIndex][showtimeIndex]);
                }
                else
                {
                    seats[movieIndex][showtimeIndex][rowIndex][columnIndex] = '.'; // Reset seat to '.'
                    printf("\n[Success] Booking for Seat %c%d [%s - %s] has been canceled!\n",
                           rowChar, column, movies[movieIndex], showtimes[movieIndex][showtimeIndex]);
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
