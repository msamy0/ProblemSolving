int lonelyinteger(int a_count, int* a) {
 
 int i =0;
 for(i = 0 ; i < a_count ; i++)
 {
     int counter=0;
     for (int j = 0 ; j < a_count ; j++)
     {
         if (a[i] == a[j])
         {
             counter++;
         }
     }
     if (counter <= 1)
     {
         break;
     }
 }   
 return a[i];
}