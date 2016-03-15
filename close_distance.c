/* Functions that compute the closest distance between two elements of an array.
 * Includes main runner.
 * 
 * Programmer - Nick Martinez
 * Date Last Modified - March 15, 2016
 */
#include <stdio.h>
#include <stdlib.h>

int pre_closest_distance(int a[], int length);	// find closest distance between two elements
int comparison(const void *a, const void *b);	// comparison function needed for 
						// stdlib qsort

int main(int argc, char **argv){

	int *a;
	int length = 8;
	a = (int[]){ 50, 45, 44, 40, 35, 30, 25, 20 };

	printf("%d\n", pre_closest_distance(a, length));

	return EXIT_SUCCESS;
}

/* Compares two integers.
 * Returns 1 if a > b, -1 if a < b, and 0 if a = b.
 */
int comparison(const void *a, const void *b){
	int int_a = *((int*)a);
	int int_b = *((int*)b);
	return ( int_a > int_b ? 1 : ( int_a < int_b ? -1 : 0 ) );
}

/* Computes the closest distance between any two elements in a.
 * Returns the closest distance.
 */
int pre_closest_distance(int a[], int length){
	if( length > 1 ){
		/* presorting */
		qsort(a, length, sizeof(*a), comparison);

		int closest = abs(a[1]-a[0]);
		int i;
		for( i = 1; i <= length-2; i++ ){
			int current_distance = abs(a[i++]-a[i]);
			if( current_distance < closest ){
				closest = current_distance;
			}
		}

		return closest;		
	}

	return 0;	// there is only one element in a
}
