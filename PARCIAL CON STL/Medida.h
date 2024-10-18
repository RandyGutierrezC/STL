#ifndef MEDIDA_H_INCLUDED
#define MEDIDA_H_INCLUDED
#include<string.h>
using namespace std;
class Medida{
    private:
        int IdMedida;
        string unidadMedida;
    public:
        Medida(){
           this->IdMedida = 0;
        }
        Medida(int id, string uM){
            this->IdMedida = id;
            this->unidadMedida = uM;
        }
        void setIdMedidas(int id){
            this->IdMedida = id;
        }
        int getIdMedida(){
            return this->IdMedida;
        }
        void setUnidadMed(string um){
            this->unidadMedida = um;
        }
        string getUnidadMed(){
            return this->unidadMedida;
        }

};


#endif // MEDIDA_H_INCLUDED
