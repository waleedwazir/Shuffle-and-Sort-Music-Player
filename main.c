#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"


int main(void)
{
    //The array containing artists names
    char artists[4][80];
    //The array containing the sorted artists
    char sortedArtists[4][80];
    //Songs for Artist 1
    char songsArtist1[3][80];
    //Songs for Artist 2
    char songsArtist2[3][80];
    //Songs for Artist 3
    char songsArtist3[3][80];
    //Songs for Artist 4
    char songsArtist4[3][80];
    //The total number of artists (Note it can be less than 4)
    int numOfArtists = 0;
    //The total number of songs for each artist (Note that less than 3 songs can be provided for each artist)
    int numSongsPerArtist[4];
    //Array to store all the songs together
    char playList[12][80];
    //keeps track of original index for artists
    int index[4] = {0, 1, 2, 3};
    //number of all songs
    int numOfSongs = 0;
    //shuffled songs
    char shuffled[12][80];



/*
 * Use here functions that you should implement to insert artists and songs from the standard input.
 * Note that you also need to track the number of artists and the number of songs for each artist.
 */
    //functions sets each index in the string to an empty value to avoid garbage values appearing
    setEmpty(songsArtist1, 3);
    setEmpty(songsArtist2, 3);
    setEmpty(songsArtist3, 3);
    setEmpty(songsArtist4, 3);
    setEmpty(playList, 12);
    setEmpty(shuffled, 24);

    //takes in number of artists from the user
    printf("Enter the amount of artist's between: 1-4: \n");
    scanf("%d", &numOfArtists);
    getc(stdin);

    //function to get all input e.g Artist names, and songs of each artist
    inputArtist(artists, songsArtist1, songsArtist2, songsArtist3, songsArtist4, numOfArtists, numSongsPerArtist);

    //this keeps track of all the songs entered
    for (int i = 0; i < numOfArtists; i++) {
        numOfSongs += numSongsPerArtist[i];
    }
/*
 * Use here the function sortArtists to sort the array of the artists and sortSongs to sort the songs of each artist
 * Print each artist (alphabetically) and for each of them print the list of songs sorted alphabetically
 */

    // copys artists to sortedartists array
    copyStrings(artists, sortedArtists, numOfArtists);

    // this sorts the sortedArtists array
    sortArtists(sortedArtists, numOfArtists, index);


    //sorts songs using the bubblesort algorithm function created for each artist given the numOfArtists
    for(int n = 0; n < numOfArtists; n++){
        switch(n){
            case 0:
                sortSongs(songsArtist1, numSongsPerArtist, 0);
                break;
            case 1:
                sortSongs(songsArtist2, numSongsPerArtist, 1);
                break;
            case 2:
                sortSongs(songsArtist3, numSongsPerArtist, 2);
                break;
            case 3:
                sortSongs(songsArtist4, numSongsPerArtist, 3);
                break;

        }
    }

    //prints out the sorted artists and songs in alphabetical order
    for(int p = 0; p < numOfArtists;p++){
        printf("%s", sortedArtists[p]);
        for (int x = 0; x < numSongsPerArtist[index[p]]; x++) {

            if(index[p] == 0) {
                printf("- %s", songsArtist1[x]);
            }else if(index[p] == 1){
                printf("- %s", songsArtist2[x]);
            }else if(index[p] == 2){
                printf("- %s", songsArtist3[x]);
            }else if(index[p] == 3){
                printf("- %s", songsArtist4[x]);
            }
        }
    }

    /*
    * Use here the function shuffleSongs to shuffle all the songs
    * Print the list of shuffled songs
    */
    // just a new line
    printf("\n");

    //we create a new char array called playList and copy all songs of each artist to it this array will then be used for the shuffle function
    newList(playList, artists, numSongsPerArtist, numOfArtists, songsArtist1,songsArtist2,songsArtist3, songsArtist4);


//    for (int o = 0; o < numOfSongs; o++) {
//        printf("%s", playList[o]);
//    }

    //this function shuffles the playlist using the fisher yates algorithm and returns a new array called shuffled which is shuffled
    shuffleSongs(playList, shuffled, numOfSongs);

    //print statement that loops the shuffled array and prints out the songs
    printf("SHUFFLED PLAYLIST: \n");

    for (int i = 0; i < numOfSongs ;i++) {
        printf("%s", shuffled[i]);
    }
    for (int i = 0; i < numOfSongs ;i++) {
        printf("%s", playList[i]);
    }


    return 0;
}
