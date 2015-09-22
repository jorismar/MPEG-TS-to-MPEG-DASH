#include <cstdio>
#include <cstdlib>

typedef char * tElement;

class Buffer {
    private:
        int r_pos;          // Posi��o de Leitura para next();
        int w_pos;          // Posi��o de Escrita para add();
        int buff_size;      // Tamanho do Buffer
        int elem_size;      // Tamanho do elemento
        tElement * buffer;  // Tamanho do buffer
        
    public:
        /**
         * Construtor
         * 
         * @param size      tamanho do buffer
         * @param elem_size tamanho do elemento
         */
        Buffer(int size, int elem_size);

        /**
         * Destrutor
         */
        virtual ~Buffer();
        
        /**
        * L� o pr�ximo elemento do buffer
        *
        * @return retorna o pr�ximo elemento do buffer
        */
        tElement next();

        /**
         * Recupera um elemento espec�fico do buffer
         *
         * @param index Indice da posi��o do buffer
         * @return      Elemento da posi��o solicitada ou NULL se
         *              o index for inv�lido
         */
        tElement get(int index);

        /**
         * Adiciona um novo elemento no Buffer
         *
         * @param elem elemento a ser adicionado
         */
        void add(tElement elem);        

        /**
         * Atribui um novo elemento numa posi��o especifica do buffer
         *
         * @param index Indice da posi��o do buffer
         * @param elem  Elemento a ser adicionado
         * @return      0 se bem sucedido ou 1 se o index for inv�lido
         */
        int set(int index, tElement elem);
        
        
        /**
         * Remove um elemento do buffer
         *
         * @param index Indice da posi��o do buffer
         * @return      Elemento removido ou NULL se o index for inv�lido
         */
        tElement remove(int index);
};