Programação Paralela

Aluno:Henrique Velho

Professora: Andrea Charão;

T3 Openmp

O presente trabalho foi criado, compilado e executado em um notebook Dell Inspiron Intel core I53337u

1- Schedule Static ()

	Neste caso como o proprio nome diz, o numero de iteracao será o mesmo, gerando uma saida uniforme;

2- Schedule Dynamic Com tratamento da exclusão mutua ()

3- Schedule Guided Com tratamento da exclusão mutua ()

	Neste caso o numero de iteraçoes irá variar, comecando por um numero grande e reduzindo ao final, como podemos ver na saida do programa(C>B>A)

4- Schedule Runtime ()

	A decisao eh feita na execução do programa

5- Schedule Auto e sem tratamento da exclusão mutua ()

	Neste caso não foi feito a omp critical o qual libera o acesso a qualquer thread e a qualquer momento, e a saida é um resultado errado;
