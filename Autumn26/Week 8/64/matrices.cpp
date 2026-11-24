#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

int scalar_two(std::vector <double>& vectora, std::vector <double>& vectorb){
    int scalarprod = 0;

    for(int i = 0; i < vectora.size();i++){
        int mult = vectora[i]*vectorb[i];
        scalarprod = scalarprod + mult;
    }
    return scalarprod;
}
std::vector<double> line_to_vector(std::string s){

    std::stringstream ss;
    std::string tmp;
    std::vector<double> out;

    ss << s;
    while(ss >> tmp){
        out.push_back(std::stod(tmp));
    }
    return out;
}
std::vector <std::vector <double>> matrix_from_file(std::string filename){
    std::vector <std::vector <double>> matrixa;
    std::string tmp;
    std::ifstream filereader;
    filereader.open(filename);
    if (!filereader.is_open()){
        std::cout << "error opening files" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    while (std::getline(filereader,tmp)){
        std::vector <double> linevec = line_to_vector(tmp);
        if (!linevec.empty()){
            matrixa.push_back(linevec);
        }
    }
    return matrixa;
}
std::vector <double> get_column(const int& col_idx, const std::vector <std::vector <double>>& matrix){
    std::vector <double> col;
    if(col_idx >= matrix[0].size()){
        std::cout << "Error: index out of range"<<std::endl;
        std::exit(EXIT_FAILURE);
    }
    for (std::vector <double> row: matrix){
        col.push_back(row[col_idx]);
    }
    return col;
}
bool ensure_mult_integrity(const std::vector <std::vector <double>>& matrix_a, const std::vector <std::vector <double>>& matrix_b){
    int m = matrix_a.size();
    int na = matrix_a[0].size();
    int nb = matrix_b.size();
    int p = matrix_b[0].size(); 
    if (na != nb){
        std::cout << "invalid dimensions"<<std::endl;
        return false;
    }
    for (std::vector <double> rowa : matrix_a){
        if (rowa.size()!=na){
        std::cout << "invalid dimensions"<<std::endl;
            return false;
        }
    }
    for (std::vector <double> rowb : matrix_b){
        if (rowb.size()!=p){
            std::cout << "invalid dimensions"<<std::endl;
            return false;
        }
    }
    return true;
}
std::vector <std::vector <double>> multiply_mat( std::vector <std::vector <double>>& matrix_a, std::vector <std::vector <double>>&  matrix_b){
    if (!ensure_mult_integrity(matrix_a,matrix_b)){
        std::exit(EXIT_FAILURE);
    }
    int m = matrix_a.size();
    int n = matrix_a[0].size();
    int p = matrix_b[0].size(); 
    std::vector <std::vector <double>> mat_prod;
    for (int rowa = 0; rowa < m;rowa++){
        std::vector <double> interim_v;
        for (int colb = 0; colb < p; colb++){
            double mat_value = 0;
            //for (int j = 0; j < n; j++ ){
            //    mat_value += matrix_a[rowa][j] * matrix_b[j][colb];
            //}
            //mat_value is the scalar product of the row of a and column of b, u can do both but i feel this the same the programming version
            //here is using scalar_two and grabbing columns too in comments
            std::vector <double> columnb = get_column(colb,matrix_b);
            mat_value = scalar_two(matrix_a[rowa],columnb);
            interim_v.push_back(mat_value);
        }
        mat_prod.push_back(interim_v);

    }
    return mat_prod;
}
int main(){
    std::string afilename = "matrixa.txt";
    std::string bfilename = "matrixb.txt";
    std::vector <std::vector <double>> matrix_a = matrix_from_file(afilename);
    std::vector <std::vector <double>> matrix_b = matrix_from_file(bfilename);
    std::vector <std::vector <double>> mat_prod = multiply_mat(matrix_a, matrix_b);
    for (std::vector <double> row : mat_prod){
        for (double item : row){
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}