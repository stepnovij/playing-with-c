#include <stdio.h>
#include <stdlib.h>

// rsrx + rqrs = sssz 
/*

q = 0

0 < r <= 4
0 < s <= 9
0 < z <= 9
x + s = z 
r = s/2
*/


int smart();
int count();
int bruteforce();
void print_result(int r, int s, int x, int z);



int main() {
   printf("rsrx + rqrs = sssz\n");
   printf("---------------smart---------------\n");
   smart();
   printf("---------------bruteforce----------\n");
   bruteforce();
}

int smart() {
   int r, s, x, z, q;
   for (r = 1; r <= 4; r++){
   	  s = r * 2;
   	  for (x = 0; x <= 9; x++) {
   	  	z = x + s;
   	  	if (z <= 9 && z > 0) {
   	  		print_result(r, s, x, z);
   	  	}
   	  }
   }
   return 0;
}

int bruteforce() {
   int r, s, x, z, q;
   char first[5], second[5], results[5];
   int first_val, second_val, results_val;

   for (r = 1; r <= 9; r++){
      for (s = 1; s <= 9; s++){
        for (x = 0; x <= 9; x++){
   	       for (z = 0; z <= 9; z++){
   	       	  for (q = 0; q <= 9; q++){
   	          	
   	          	sprintf(first, "%d%d%d%d", r,s,r,x);
   	          	sprintf(second, "%d%d%d%d", r,q,r,s);
   	          	sprintf(results, "%d%d%d%d", s,s,s,z);

                first_val = atoi(first);
                second_val = atoi(second);
                results_val = atoi(results);

                if (first_val + second_val == results_val) {
                	printf("%d + %d = %d  it's n=%d\n", first_val, second_val, results_val, count());
                }
   	          }
	       }
	    }	
      }	
   }
   return 0;
}

int count() {
	static int count = 1;
	return count++;
}

void print_result(int r, int s, int x, int z) {
	printf("%d%d%d%d + %d0%d%d = %d%d%d%d  it's n=%d\n", r,s,r,x,r,r,s,s,s,s,z, count());
}