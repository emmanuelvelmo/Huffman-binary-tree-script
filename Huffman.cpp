#include<iostream>
#include<string>

std::string* generar_canonicos(unsigned char (&dht2)[16], unsigned short &tam_arr2)
{
    for (unsigned short i = 0; i < 16; i++)
    {
        tam_arr2 += dht2[i];
    }

    std::string* inst_codigos = new std::string[tam_arr2];
    std::string gen_codigo = "0";

    unsigned short m = 0;
    for (unsigned short i = 0; i < 16; i++)
    {
        for (unsigned short m2 = 0; m2 < dht2[i]; m2++)
        {
            inst_codigos[m++] = gen_codigo;

            short ite_str = gen_codigo.size() - 1;
            while (ite_str >= 0 && gen_codigo[ite_str] == '1')
            {
                gen_codigo[ite_str] = '0';
                --ite_str;
            }
            if (ite_str >= 0)
            {
                gen_codigo[ite_str] = '1';
            }
        }

        gen_codigo += "0";
    }

    return inst_codigos;
};

struct nodo
{
    nodo(const std::string& cod_nodo2 = "", unsigned char valor_nodo2 = '\0') : cod_nodo(cod_nodo2), valor_nodo(valor_nodo2) {}
    
    std::string cod_nodo;
    unsigned char valor_nodo;
    nodo* nodo_izq = nullptr;
    nodo* nodo_der = nullptr;
};

nodo* preorden_insertar(const std::string &codigos_canonicos_xx, const unsigned char &xxx_xx_nod, nodo* raiz_xx)
{
    for (unsigned short i = 0; i < codigos_canonicos_xx.size(); i++)
    {
        if (codigos_canonicos_xx[i] == '0')
        {
            if (!raiz_xx->nodo_izq)
            {
                raiz_xx->nodo_izq = new nodo(codigos_canonicos_xx.substr(0, i + 1), (i + 1 == codigos_canonicos_xx.size()) ? xxx_xx_nod : '\0');
            }

            raiz_xx = raiz_xx->nodo_izq;
        }
        else
        {
            if (!raiz_xx->nodo_der)
            {
                raiz_xx->nodo_der = new nodo(codigos_canonicos_xx.substr(0, i + 1), (i + 1 == codigos_canonicos_xx.size()) ? xxx_xx_nod : '\0');
            }

            raiz_xx = raiz_xx->nodo_der;
        }
    }

    return raiz_xx;
};

void postorden_remover(nodo* &raiz_xx2)
{
    if (!raiz_xx2) return;

    postorden_remover(raiz_xx2->nodo_izq);
    postorden_remover(raiz_xx2->nodo_der);

    delete raiz_xx2;
};

int main()
{
    unsigned char dht_00[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    std::string lum_dc_nod;
    
    unsigned short tam_arr_00 = 0;
    std::string* codigos_canonicos_00 = generar_canonicos(dht_00, tam_arr_00);
    
    nodo* raiz_00 = nullptr;
    for (unsigned short i = 0; i < tam_arr_00; i++)
    {
        raiz_00 = preorden_insertar(codigos_canonicos_00[i], lum_dc_nod[i], raiz_00);
    }
    
    postorden_remover(raiz_00);
    
    return 0;
}
