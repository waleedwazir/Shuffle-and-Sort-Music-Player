#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"
#include <stdlib.h>
#include <time.h>

/*
 * InputArtist Function: Will take in input from user and fill in the arrays
 * Takes 7 variables.
 * Artists: array to store the Name of the artists
 * Song1 - song4: 4 arrays to store the songs of each artists.
 * NumOfArtists: the number of artists the user plans to input
 * NumOfSongsPerArtists: An array which will record how many songs each artist will have
 */

void inputArtist(char artists[][80], char song1[][80], char song2[][80], char song3[][80], char song4[][80], int numOfArtists, int numOfSongsPerArtist[4]){
    //this is to a check to see if the user wants to stop adding songs to a artist
    int check;
    //loops certain amount of times and asks for Artist name
    for(int i = 0; i < numOfArtists ; i++) {
        printf("Insert an artist/group name: ");
        //saves the artist name into the array using fget function
        fgets(artists[i], 80, stdin);
        //getc(stdin);

        //this loop is to add the songs for each artists
        //when artist name is inputted, it will then come to this loop and ask the user to input 1-3 songs depending on the user
        for(int j = 0; j < 3; j++){
            printf("Insert song %d for %s ", j + 1, artists[i]);
            //getc(stdin);

            //switch case to identify which artist we are on, so we can correspond to its songArtist array
            switch(i){
                case 0:
                    fgets(song1[j], 80, stdin);
                    break;
                case 1:
                    fgets(song2[j], 80, stdin);
                    break;
                case 2:
                    fgets(song3[j], 80, stdin);
                    break;
                case 3:
                    fgets(song4[j], 80, stdin);
                    break;
            }

            //check to see if all 3 songs are added if so skip to next artist, if not countinue below
            if(j == 2){
                numOfSongsPerArtist[i] = j + 1;
                break;
            }
            //this is a prompt to the user to check if they want to continue to add songs or stop after adding the first song.
            //if they type 1, program will ask to add 2nd song.
            //if they type 3, it will break out of the loop and continue onto the other artist or artists.
            printf("(Type 1 to add more songs) or (Type 2 to finish): ");
            scanf("%d", &check);
            getc(stdin);


            if(check == 2){
                //this keeps track on how many songs each artist has
                numOfSongsPerArtist[i] = j + 1;
                break;
            }
        }
    }
}

/*
* This method sorts the artists alphabetically. It takes as input:
* - sortedArtists: the array of artists that that should be sorted
* - numOfArtists: the total number of artists
*
*/
//The sortArtists function takes string array and its size as parameters
// and sorts the strings alphabetically using a bubble sort algorithm.
void sortArtists(char sortedArtists[][80] , int numOfArtists, int index[]){
    //temporarily holds the string that would be replaced using strcpy function
    char temp[80];
    //this keeps track of the original index's of the Artists before they are sorted
    int tempIndex;

    //2 for loops, loop through each artist inside of the array and compare the strings char ascii values.
    for(int i = 0; i < numOfArtists - 1; i++){
        for(int j = 0; j < numOfArtists - i - 1; j++){
            //strcmp is a function that compares the ascii values
            if (strcmp(sortedArtists[j], sortedArtists[j+1]) > 0){
                //strcpy is a built in function that copys the string to another string
                strcpy(temp, sortedArtists[j]);
                strcpy(sortedArtists[j], sortedArtists[j+1]);
                strcpy(sortedArtists[j+1], temp);
                //this is changing the values inside of the int index array which will help keep track of the artists original index's
                //this will allows us to print out the songs for the artist
                tempIndex = index[j];
                index[j] = index[j+1];
                index[j+1] = tempIndex;
            }
        }
    }
}


//copys artists name to sortedartists
void copyStrings(char artists[][80], char sortedArtists[][80], int numOfArtists){
    for(int i = 0; i < numOfArtists; i++){
        //strcpy copying strings of an array to another array
        strcpy(sortedArtists[i], artists[i]);
    }
}

/*
* This method sorts the songs of a specific artist alphabetically. It takes as input:
* - songsOfAnArtist: the array of the songs of an artist that was provided from the standard input
* - numOfSongsPerArtist: array of the number of songs per artists provided from the standard input.
* - int no, which indicates which songs array belongs to which artist
*/

void sortSongs(char songsOfAnArtist[][80], int numOfSongPerArtist[], int no){
    char temp[80];
    //sorts the songs using bubble sort
    for (int i = 0; i < numOfSongPerArtist[no] - 1; i++){
        for (int j = 0; j < numOfSongPerArtist[no] - i - 1; j++){
            //compares if str1 is less then str2, if true it will switch the two strings in the array
            if (strcmp(songsOfAnArtist[j], songsOfAnArtist[j+1]) > 0){
                strcpy(temp, songsOfAnArtist[j]);
                strcpy(songsOfAnArtist[j], songsOfAnArtist[j+1]);
                strcpy(songsOfAnArtist[j+1], temp);
            }
        }
    }
}

/*
* This method shuffles a set of songs. It takes as input:
* - songsToBeShuffled: the array of the songs that should be shuffled
* - numOfSongs: the number of songs to be shuffled
* - shuffled: copy of the array of songs inputted
*/

void shuffleSongs(char songsToBeShuffled[][80], char shuffled[][80], int numOfSongs){
    //srand makes sure that j, which is our random number, will always be random with no set seed
    srand(time(NULL));
    //will use to store string that will be switched
    char swap[80];
    //this will store the last 5 previous strings sorted to make sure that there is atleast 5 other strings printed before the same string prints
    char check[80];
    char check2[80];
    char check3[80];
    char check4[80];
    char check5[80];

    //copying array PlayList to Shuffled
    for (int c = 0; c < numOfSongs; c++) {
        strcpy(shuffled[c], songsToBeShuffled[c]);
    }

    //if theres less then 6 songs cant shuffle with atleast 5 different strings so it will just shuffle ignoring that case.
    //if there is songs more then 5 then it will shuffle with atleast 5 different strings inbetween.
    if(numOfSongs <= 5){
        for(int i = 1; i < numOfSongs; i++){
            int n = rand()%(numOfSongs);

            if(n!=i){
                strcpy(swap, shuffled[n]);
                strcpy(shuffled[n], shuffled[i]);
                strcpy(shuffled[i], swap);
            }
        }
        for(int i = 1; i < numOfSongs; i++){
            int n = rand()%(numOfSongs);

            if(n!=i){
                strcpy(swap, songsToBeShuffled[n]);
                strcpy(songsToBeShuffled[n], songsToBeShuffled[i]);
                strcpy(songsToBeShuffled[i], swap);
            }
        }
    }else{
        //using the fisher yates algorithms ill shuffled two arrays
        for(int i = 1; i < numOfSongs; i++){
            //this will pick a random number in the array and switch it with the index i.
            int j = rand()%(numOfSongs);

            //while loop to check if we have used the new j before by comparing the strings with the 5 previous strings that appeared.
            while(strcmp(shuffled[j], check) == 0 || strcmp(shuffled[j], check2) == 0 || strcmp(shuffled[j], check3) == 0 || strcmp(shuffled[j], check4) == 0 || strcmp(shuffled[j], check5) == 0){
                j = rand()%(numOfSongs);
            }

            //updating the checks each time the array is shuffled
            strcpy(check5, check4);
            strcpy(check4, check3);
            strcpy(check3, check2);
            strcpy(check2, check);
            strcpy(check, shuffled[j]);

            //if it isnt the same index we swap the two strings
            if(j!=i){
                strcpy(swap, shuffled[j]);
                strcpy(shuffled[j], shuffled[i]);
                strcpy(shuffled[i], swap);
            }
        }

        for(int i = 1; i < numOfSongs; i++){
            int j = rand()%(numOfSongs);

            while(strcmp(songsToBeShuffled[j], check) == 0 || strcmp(songsToBeShuffled[j], check2) == 0 || strcmp(songsToBeShuffled[j], check3) == 0 || strcmp(songsToBeShuffled[j], check4) == 0 || strcmp(songsToBeShuffled[j], check5) == 0){
                j = rand()%(numOfSongs);
            }

            strcpy(check5, check4);
            strcpy(check4, check3);
            strcpy(check3, check2);
            strcpy(check2, check);
            strcpy(check, shuffled[j]);

            if(j!=i){
                strcpy(swap, songsToBeShuffled[j]);
                strcpy(songsToBeShuffled[j], songsToBeShuffled[i]);
                strcpy(songsToBeShuffled[i], swap);
            }
        }
    }
}

//this function sets arrays to empty strings
//takes an array and the num of rows in the array
void setEmpty(char arr[][80], int rows){
    for (int i = 0; i < rows; i++) {
        //copying empty string to each index of the array
        strcpy(arr[i], "");
    }
}

/* NEWLIST function
 * This function adds all the songs of each artist into one array called playList
 * This functions takes 8 variables
 * playList: An empty array to store all the songs in
 * Artists: name of the artists taken at input
 * numSongsPerArtist: int array which stores how many songs each artist has taken at input
 * numOfArtists: amount of artists taken in at input
 * song1 - song4: the array of songs of each artist taken at input
 */
void newList(char playList[][80], char Artists[][80], int numSongsPerArtist[], int numOfArtists, char song1[][80], char song2[][80], char song3[][80], char song4[][80]){

    //will keep track on which index we are on in the new array
    int j, k, m, v;
    //dash string to add between the song and the name of the artist to create a new string inside of the new array
    char dash[] = " - ";

    //loops how mnay times depending on the amount of artists, 1-4
    for(int i = 0; i < numOfArtists;i++){
        //depending on i which indicates which artist we start with
        switch(i){
            case 0:
                //copyings all songs of that artist into the new array with the artist name at the start
                for(j = 0; j < numSongsPerArtist[0];j++){
                    strcpy(playList[j], Artists[i]);
                    strcat(playList[j], dash);
                    strcat(playList[j], song1[j]);
                }
                break;
            case 1:
                for(k = j; k < j + numSongsPerArtist[1];k++){
                    strcpy(playList[k], Artists[i]);
                    strcat(playList[k], dash);
                    strcat(playList[k], song2[k - j]);
                }
                break;
            case 2:
                for( m = k; m < k + numSongsPerArtist[2];m++){
                    strcpy(playList[m], Artists[i]);
                    strcat(playList[m], dash);
                    strcat(playList[m], song3[m - k]);
                }
                break;
            case 3:
                for(v = m; v < m + numSongsPerArtist[3];v++){
                    strcpy(playList[v], Artists[i]);
                    strcat(playList[v], dash);
                    strcat(playList[v], song4[v - m]);
                }
                break;
        }
    }
}
