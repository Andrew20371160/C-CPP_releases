#include <iostream>
#include <random>
#include <time.h>
using namespace std ;

class matrix{
public:

int rows ,cols ;
int **mat ;

matrix(){
    mat= NULL ;
    rows= 0 ; cols = 0;
}

matrix(int r , int c  ){
        rows = r ;
        cols = c ;
        //allocate memory for 2d matrix
        //allocate array of pointers
        mat = new int*[rows] ;
        //for each pointer in the array allocate an array[cols]
        for(int i = 0 ; i <rows;i++){
            mat[i] = new int[cols] ;
        }
        //initialize allocated matrix with zeroes
            for(int i = 0 ; i<rows;i++){
                for(int j = 0  ; j<cols ; j++){
                    mat[i][j] = 0;
                }
            }

}

~matrix(){
    //first delete each entry of the 2d array (matrix)
    for(int i = 0 ; i <rows;i++){
       delete []mat[i] ;
    }
    //then delete the array of pointers
    delete mat ;
 }


//this function initializes the matrix with  sequence of 9 numbers
//this note that the returned matrix has specifications for hillcipher
//det(matrix)!=13 and det(mat)!=0 and det(mat) is odd
void get_key(void);
//checks if current matrix is identity matrix
bool identity(void);
//multiply 2 matrices and put the result in the caller
void mat_mult(matrix*,matrix*);
//returns determanint of the matrix
int det(void) ;

void inverse(matrix*) ;

int get_ele(int i , int j){
    if(i<rows&&j<cols){
        return mat[i][j] ;
    }
    return -1 ;
}
void operator = (matrix*src_mat);
//displays elements of the matrix
void show(void) ;
};

int matrix ::det(void){
    //used in collecting summition elements
    int arr[4];
    //counter for inserting sum elements in the prev array
    int counter =0;
    //return value
    int sum = 0;
//for each element in the first row
for(int i =0 ; i <rows;i++){
    //go through lower elements
    for(int row_c = 1 ; row_c <rows ;row_c++){
        for(int col_c = 0 ; col_c <cols;col_c++){
         //where the col counter isn't equal to the ith value
            if(col_c!=i){
                //collect sum elements
                arr[counter] =mat[row_c][col_c];
                counter++;
            }
        }
    }
    //to collect the new elements remember to restart counter at zero
    counter = 0;
    if(i==1){
        //for the second element in the first row we subtract the determanint of the small matrix
        sum-=mat[0][i]*(arr[0]*arr[3]-arr[1]*arr[2]) ;
    }
    else{
    sum += mat[0][i]*(arr[0]*arr[3]-arr[1]*arr[2]) ;
    }
}
return sum ;
    /*
    if(isSquare()){
Matrix mat_cpy =*this;
for(int up_r = 0;up_r<rows-1; up_r++){
    for(int low_r = up_r+1; low_r<rows; low_r++){
        //check first if upper element is not zero
        if(mat_cpy.data[up_r][up_r]==0){
            //switch the rows
            for(int i = 0 ;  i<cols;i++){
                float temp = mat_cpy.data[up_r][i]  ;
                mat_cpy.data[up_r][i] = mat_cpy.data[low_r][i] ;
                mat_cpy.data[low_r][i]= temp;
            }
        }
        else{
            float c = -1*(mat_cpy.data[low_r][up_r]/mat_cpy.data[up_r][up_r]);
            for(int i =0 ; i<cols;i++){
                mat_cpy.data[low_r][i]+=c*mat_cpy.data[up_r][i] ;
            }
        }
    }
}
float det = 1 ;
for(int i =0 ; i <rows; i++){
    det*=mat_cpy.data[i][i]  ;
}
return det ;

    
    */
}

void matrix ::mat_mult(matrix *mat1,matrix *mat2){
if(mat1->cols==mat2->rows){
    for(int row_c =0 ; row_c <mat1->rows;row_c++){

        for(int col_c= 0 ; col_c<mat2->cols ; col_c++){

            mat[row_c][col_c] = 0;

            for(int ele_c = 0 ; ele_c <3 ;ele_c++){
                mat[row_c][col_c]+=(mat1->mat[row_c][ele_c]*
                        mat2->mat[ele_c][col_c])%26;
            }
        }
    }
}
}

void matrix ::get_key(void){

int det_val  = 0;

srand(time(0));
//keep generating random keys until their determinant meets these conditions
while( !((det_val!=0)&&(det_val%2!=0)&&(det_val!=13))){
    for(int i = 0 ; i <3;i++){
        for(int j= 0 ; j<3 ;j++){
            //get a random number from 0 to 25 (notice the modulus)
            mat[i][j] = rand()%26;
        }
    }
    //get determinant of generated key
    det_val= det() ;
}
}


bool matrix::identity(void){
for(int i = 0 ; i <rows ; i++){
    for(int j= 0 ; j<cols ; j++){
        if(i!=j){
           mat[i][j]=0;
        }
        else{
            mat[i][j]=1;
            }
        }
    }
    return true ;
}

void matrix::show(void){

    for(int i = 0 ; i <rows ; i++){
        for(int j=  0 ;  j<cols ; j++){
            cout<<mat[i][j]<<" " ;
        }
        cout<<endl ;
    }
}

void encrypt(matrix *key , char *text ){
int counter = 0;

matrix text_mat(3,1) ;

matrix cipher_mat(3,1) ;
//this loops goes through each 3 elements
while(*(text+counter)){
    //copy the string indices into the matrix
    for(int i =counter;i<(counter+3);i++){
        text_mat.mat[i-counter][0]=text[i]-'a';
    }
    cipher_mat.mat_mult(key,&text_mat) ;

    for(int i = counter ; i <(counter+3);i++){
        text[i] ='a'+abs(cipher_mat.mat[i-counter][0]%26);
    }
    counter+=3 ;
    }
}

void matrix ::operator=(matrix*src_mat){
for(int  i = 0 ; i <rows;i++){
    for(int j = 0 ; j<cols;j++){
        mat[i][j] = src_mat->mat[i][j];
    }
}
}
// Function to calculate the modular multiplicative inverse
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;  // Return -1 if the modular inverse does not exist
}

void matrix::inverse(matrix* mat1){
    matrix mat_cpy(3,3);

    mat_cpy = *mat1;
    //make the the current matrix identity
    identity();

    for(int up_r = 0 ; up_r<rows-1;up_r++){
        for(int low_r = up_r+1;low_r<rows;low_r++){
            int c = -1 * ((mat_cpy.mat[low_r][up_r] * modInverse(mat_cpy.mat[up_r][up_r], 26)) % 26);
            for(int col_c = 0 ; col_c<3 ; col_c++){
                mat_cpy.mat[low_r][col_c] = (mat_cpy.mat[low_r][col_c] + c*mat_cpy.mat[up_r][col_c]) % 26;
                mat[low_r][col_c] = (mat[low_r][col_c] + c*mat[up_r][col_c]) % 26;
            }
        }
    }

    for(int low_r = 2 ; low_r>0;low_r--){
        for(int up_r = low_r-1;up_r>=0;up_r--){
            int c = -1 * ((mat_cpy.mat[up_r][low_r] * modInverse(mat_cpy.mat[low_r][low_r], 26)) % 26);
            for(int col_c = 0 ; col_c<3 ; col_c++){
                mat_cpy.mat[up_r][col_c] = (mat_cpy.mat[up_r][col_c] + c*mat_cpy.mat[low_r][col_c]) % 26;
                mat[up_r][col_c] = (mat[up_r][col_c] + c*mat[low_r][col_c]) % 26;
            }
        }
    }

    for(int i= 0 ; i<3;i++){
        int inv = modInverse(mat_cpy.mat[i][i], 26);
        for(int j= 0 ; j<3 ; j++){
            mat[i][j] = (mat[i][j] * inv) % 26;
        }
    }
}

void decrypt(matrix*key , char * text ){
matrix inv_key(3,3) ;
inv_key.inverse(key)  ;
int counter = 0;

matrix text_mat(3,1) ;

matrix cipher_mat(3,1) ;
//this loops goes through each 3 elements
while(*(text+counter)){
    //copy the string indices into the matrix
    for(int i =counter;i<(counter+3);i++){
        cipher_mat.mat[i-counter][0]=text[i]-'a';
    }
    text_mat.mat_mult(&inv_key,&cipher_mat) ;

    for(int i = counter ; i <(counter+3);i++){
        text[i] ='a'+abs(text_mat.mat[i-counter][0]%26);
    }
    counter+=3 ;
    }

}
int main(){
matrix key(3,3) ;
key.get_key() ;

char text[] = "heyimcallingsincethe";
encrypt(&key,text) ;
cout<<text ;
decrypt(&key , text) ;
cout<<endl<<text ;
    return  0;
}


