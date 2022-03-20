#include <stdio.h>    /* printf(), scanf() */
#include <stdbool.h>  /* tipo bool         */

#include <assert.h>   /* assert() */

struct max_min_result {
    int max_value;
    int min_value;
    unsigned int max_position;
    unsigned int min_position;
};

struct max_min_result compute_max_min(int array[], unsigned int length)
{
    assert(length > 0);
    struct max_min_result result;

    for (unsigned int i = 0; i < length; i++) {

      if (i==0) {
        result.max_value = array[i];
        result.min_value = array[i];
        result.max_position = 0;
        result.min_position = 0;
      }
      if (result.min_value >= array[i]) {
        result.min_value = array[i];
        result.min_position = i;
      } else if(result.max_value <= array[i]) {
        result.max_value = array[i];
        result.max_position = i;
      } else {
        continue;
      }

    }

    return result;
}

int main(void)
{

    unsigned int size;
    printf("Tamaño del array: ");
    scanf("%u", &size);
    int array[size];

    for (unsigned int i = 0; i < size; i++) {
      printf("Valor de la posición %u: ", i);
      scanf("%d", &array[i] );
    }

    struct max_min_result result = compute_max_min(array, size);
    printf("Máximo: %d\n", result.max_value);
    printf("Posición del máximo: %u\n", result.max_position);
    printf("Mínimo: %d\n", result.min_value);
    printf("Posición del mínimo: %u\n", result.min_position);
    return 0;
}
