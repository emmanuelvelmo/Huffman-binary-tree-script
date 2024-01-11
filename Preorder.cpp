#include<string>

std::string generar_canonicos(unsigned char &dht2, short &tam_arr2)
{
    for (i = 0; i < 16; i++)
    {
        tam_arr2 += dht2[i];
    }

    std::string* inst_codigos = new std::string[tam_arr2];
    std::string gen_codigo = "0";

    m = 0;
    for (i = 0; i < 16; i++)
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

unsigned short tam_arr_00 = 0;
std::string* codigos_canonicos_00 = generar_canonicos(dht_00, tam_arr_00);

unsigned short tam_arr_01 = 0;
std::string* codigos_canonicos_01 = generar_canonicos(dht_01, tam_arr_01);

unsigned short tam_arr_10 = 0;
std::string* codigos_canonicos_10 = generar_canonicos(dht_10, tam_arr_10);

unsigned short tam_arr_11 = 0;
std::string* codigos_canonicos_11 = generar_canonicos(dht_11, tam_arr_11);

struct nodo
{
    nodo(const std::string& cod_nodo2 = "", unsigned char valor_nodo2 = '\0') : cod_nodo(cod_nodo2), valor_nodo(valor_nodo2) {}

    std::string cod_nodo;
    unsigned char valor_nodo;
    nodo* nodo_izq = nullptr;
    nodo* nodo_der = nullptr;
};


nodo* (const std::string &codigos_canonicos_xx, const unsigned char &xxx_xx_nod, nodo* raiz_xx)
{
    for (i = 0; i < codigos_canonicos_xx.size(); i++)
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

nodo* raiz_00 = nullptr;
for (i = 0; i < tam_arr_00; i++)
{
    raiz_00 = preorden_insertar(codigos_canonicos_00[i], lum_dc_nod[i], raiz_00);
}

nodo* raiz_01 = nullptr;
for (i = 0; i < tam_arr_01; i++)
{
    raiz_01 = preorden_insertar(codigos_canonicos_01[i], chr_dc_nod[i], raiz_01);
}

nodo* raiz_10 = nullptr;
for (i = 0; i < tam_arr_10; i++)
{
    raiz_10 = preorden_insertar(codigos_canonicos_10[i], lum_ac_nod[i], raiz_10);
}

nodo* raiz_11 = nullptr;
for (i = 0; i < tam_arr_11; i++)
{
    raiz_11 = preorden_insertar(codigos_canonicos_11[i], chr_ac_nod[i], raiz_11);
}

void(nodo* &raiz_xx2)
{
    if (!raiz_xx2) return;

    postorden_remover(raiz_xx2->nodo_izq);
    postorden_remover(raiz_xx2->nodo_der);

    delete raiz_xx2;
};

int main()
{
    preorden_insertar();
    postorden_remover();
    
    return 0;
}
