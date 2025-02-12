#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <stdlib.h>
#include <limits.h>
#include <math.h>

/* Assumes srand() has been called with an appropriate seed at some point
   Code assumes C99 is available; minor tweaks needed for older compilers.
 */
int gen_random_int() {
    const int BITS_PER_RAND = (int)(log2(RAND_MAX/2 + 1) + 1.0); /* Or log(RAND_MAX + 1) / log(2) with older language standards */
    int ret = 0;
    for (int i = 0; i < sizeof(int) * CHAR_BIT; i += BITS_PER_RAND) {
        ret <<= BITS_PER_RAND;
        ret |= rand();
    }
    return ret;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int num = atoi(argv[1]);
	
	srand(time(NULL));

	int i = -1;
	while (++i < num)
		printf("%d ", gen_random_int());
	
	return (0);
}