#include <iostream>
#include <unistd.h>


#define A 4 
#define B 4

int**  create_arr(int a, int b);
void zero(int** arr);
void print(int** arr);
void draw_point(int** arr, int a, int b);
void free_arr(int** arr, int a);
void draw_border(int** arr);
int sum(int** arr);
void  fill_rand(int** arr);
void draw_point_rand(int** arr);
void draw_a(int** arr);
void  draw_time(int** arr);
void fill_num(int** arr);
void fill_snake(int** arr);


int main() {
    srand(time(0));
    int** arr = create_arr(A, B);
    zero(arr);
    //fill_num(arr); 
    fill_snake(arr);
    //draw_a(arr);
    // // fill_rand(arr);
    //  draw_point_rand(arr);
    //  draw_border(arr);
    // // draw_point(arr, 5, 3);
    //draw_time(arr); 
    // //sum(arr);
    print(arr);
    free_arr(arr, A);
}
// 1 0 0 0 0 0 0 0 0 0 0     
// 0 2 0 0 0 0 0 0 0 0 0
// 0 0 3 0 0 0 0 0 0 0 0
// 0 0 0 4 0 0 0 0 0 0 0
// 0 0 0 0 5 0 0 0 0 0 0
// 0 0 0 0 0 1 0 0 0 0 0
// 0 0 0 0 0 0 1 0 0 0 0
// 0 0 0 0 0 0 0 1 0 0 0
// 0 0 0 0 0 0 0 0 1 0 0
// 0 0 0 0 0 0 0 0 0 1 0
// 0 0 0 0 0 0 0 0 0 0 1


int**  create_arr(int a, int b) {
    int** arr = (int**)malloc(a * sizeof(int *));

    for(int i = 0; i < a; i++) {
        arr[i] = (int *)malloc(b * sizeof(int));// 3|0
    }



    return arr;
}


void draw_border(int** arr) {
    for(int i = 0; i < A; i++) {
        for(int j = 0; j < B; j++) {
            if(i == 0|| j == B - 1  || i == A - 1 || j == 0) {
                arr[i][j] = 2;
            } 
        }
    }



}


void zero(int** arr) {

    for(int i = 0; i < A; i++) {
        for(int j = 0; j < B; j++) {
            arr[i][j] = 0;
        }
    }


}


void print(int** arr) {

    for(int i = 0; i < A; i++) {
        for(int j = 0; j < B; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


void draw_point(int** arr, int a, int b) {
    if((a > A) || (b > B ) || a <= 0 || b <= 0) {
        std::cout << "Error" << std::endl;
        exit(0);
    } else {
        arr[a - 1][b - 1] = 11;
    }
}


void free_arr(int** arr, int a){
    for(int i = 0; i < a; i++) {
        free(arr[i]);
    }
    free(arr);
}



int sum(int** arr) {
    int sum = 0;
    for(int i = 0; i < A; i++) {
        for(int j = 0; j < B; j++) {
            sum += arr[i][j];
        }

    }
    return sum;
}

void  fill_rand(int** arr) {
  
    //2763845
    for(int i = 0; i < A; i++) {
        for(int j = 0; j < B; j++) {
            arr[i][j] = rand() % 10;
        }
    }
   
    
}
//FIXME

void draw_point_rand(int** arr) {
    int a = rand() % 9 + 1; 
    int b = rand() % 9 + 1; 


    draw_point(arr, a, b);
    
    
}









void draw_a(int** arr) {
    for(int i = 0; i < A; i++) {
        for(int j = 0; j < B; j++) {
            if(i == j) {
                arr[i][j] = 1;
            }
            if(i + j == 10) {
                arr[i][j] = 1;
            }
            if(i < j) {
                arr[i][j] = 1;
            }
            if(i + j > 10) {
                arr[i][j] = 1;
            }
            if((i == 5) && (j < 5)) {
                arr[i][j] = 1; 
            }

            if((i > 5)) {
                arr[i][j] = 1;
            }

        }
    }
}




void  draw_time(int** arr) {
    int i = A - 1;
    int j = B - 1;
    for( ;  ; ) {
        arr[i][j] = 1;   
        j--;
        std::cout <<j << " " << i << std::endl;

        if (j < 0){
            i--;
            j = B - 1;
        }

        print(arr);

        if(i < 0) {
            break;
        }



        std::cout << std::endl;
        usleep(100000);
    }



}






void fill_num(int** arr) {
    
    int a = 1;

    for(int i = 0; i < A; i++) {
        for(int j = 0; j < B; j++) {
            arr[i][j] = a;//a += 1     a = a + 1      
            a += 1;
        }
    }
}


void fill_snake(int** arr) {
    
    int a = 1;
// 0 0;  1 0; 2 0;  3 0
// 0 0;  0 1  0 2   0 3 
    for(int i = 0; i < A; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < B; j++) {
                arr[i][j] = a;    
                a += 1;
            }
        }  else {
            for(int j = B - 1; j >= 0; j--) {
                arr[i][j] = a; 
                a += 1;
              
        

            }
        }

    }

}
            

