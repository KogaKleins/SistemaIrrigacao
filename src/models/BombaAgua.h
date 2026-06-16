#ifndef BOMBAAGUA_H
#define BOMBAAGUA_H

// Model simples que representa o estado da bomba.
// A bomba nao decide quando ligar; o SistemaIrrigacao decide.
class BombaAgua {
private:
    bool ligada;

public:
    // Uso normal: a bomba nasce desligada.
    BombaAgua();

    // Construtor util para testes ou simulacoes especificas.
    BombaAgua(bool ligada);

    void ligar();
    void desligar();
    bool estaLigada();
};

#endif
