#include <omp.h>
#include <stdio.h>

int main() {
   int data, flag = 0;
   #pragma omp parallel num_threads(2)
   {
      if (omp_get_thread_num()==0) {
         /* Write to the data buffer that will be read by thread */
         data = 42;
         /* Set flag to release thread 1 */
         flag = 1;
      }
      else if (omp_get_thread_num()==1) {
         /* Loop until we see the update to the flag */
         while (flag < 1) {
         }
         /* print flag and data */
         printf("flag=%d data=%d\n", flag, data);
      }
   }
   return 0;
}
