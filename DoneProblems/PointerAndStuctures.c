/******************************
 * Code to count the number of views to a certain videos
 * based on a structure provided
 * Author : M Samy
 * Date : 2023
 * */
#include <stdio.h>
#include <stdlib.h>
typedef struct Video {
    char *name;
    int unique_views;
} Video;

typedef struct Viewer {
    char *username;
    Video *watched_videos;
    int watched_videos_size;
} Viewer;

int count_views(Viewer **viewers, int viewers_size, char *video_name)
{
  if (video_name == NULL || viewers == NULL)
  {
	  return -1;
  }
  else
  {
	int viewsCounter = 0;
    for (int localCounter1 = 0 ; localCounter1 < viewers_size ; localCounter1 ++ )
    {

    	int sizeOfVidsWatchedByViewer = ((*(viewers+localCounter1))->watched_videos_size);
    	Video * arrayOfVideosWatchedByViewer = ( (*(viewers+localCounter1))->watched_videos);
    	for (int localCounter2 = 0 ; localCounter2 < sizeOfVidsWatchedByViewer ; localCounter2++ )
    	{
    		char * nameOfCurrentRecord = (arrayOfVideosWatchedByViewer+localCounter2)->name;
    		int flagToCheckMatching = 0xFFFF;
    		int localCounter3= 0;
    		do
    		{
    			if ( *(nameOfCurrentRecord +localCounter3) != *(video_name+localCounter3) )
    			{
    				flagToCheckMatching = localCounter3; //for debugging to know the exit index
    				break;
    			}
    			localCounter3++;
    		}
    		while (localCounter3<100 && *((video_name+localCounter3)-1) != '\0'); // while last element is not terminator, loop

    		if (flagToCheckMatching == 0xFFFF)
    		{

    			viewsCounter++;
    			break;
    		}
    	}
    }
    return viewsCounter;
  }
}
#ifndef RunTests
int main()
{
    Video videos[] = { {.name = "Soccer", .unique_views = 500},
                       {.name = "Basketball", .unique_views = 1000},
					   {.name = "Toto", .unique_views = 1000},
					   {.name = "Toto", .unique_views = 1000},
					   {.name = "Bo7a", .unique_views = 1000}};
    Viewer viewer = {.username = "Bob", .watched_videos = videos,
                     .watched_videos_size = 5};

    Viewer *viewers[] = { &viewer };
    printf("%d", count_views(viewers, 1, "Toto")); /* should print 1 */
}
#endif
