/**!
 * This program implements the solution for the LP1 2016.2 exam.
 */

#include <iostream>  // cout, endl
#include <iomanip>   // setw
#include <iterator>  // distance
#include <cstdlib>   // memset, memcmp, memcpy
#include <algorithm> // copy

//<! Definição do tipo Student.
struct Student
{
    std::string name; //<! Nome do estudante.
    float grades[3];  //<! Nota unidade 1.
    int year;         //<! Ano de entrada.

    enum grade_t { N1=0, N2, N3 }; //<! Alias para cada nota.

    //<! Construtor simples.
    Student( std::string n_="", float n1_=0.f, float n2_=0.f, float n3_=0, int y_=20162 )
        : name( n_ )
        , grades {n1_, n2_, n3_}
        , year( y_ )
    { /* Empty */ }

    //! Sobrecarga do operador <<, que faz com que Student seja impresso.
    /*! @param _os Output stream, normalmente o <CODE>cout</code>.
     *  @param _s O estudante a ser impresso.
     *  @return A pr&oacute;pria <CODE>os</code> recebida como par&acirc;metros (para permitir encadeamento).
     */
    inline friend std::ostream &operator<< ( std::ostream& os_, const Student& s_ )
    {
        os_ << std::fixed << std::setprecision(1);
        os_ << "[ "  << std::setw(10) << s_.name << ", " 
            << "Notas{" << std::setw(3)  << s_.grades[N1] << "," << s_.grades[N2] << "," << s_.grades[N3] << "}, "
            << "Y="  << std::setw(6) << s_.year/10.f << std::setprecision(0)
            << "]";
        return os_;
    }
};




// ================================================================================
// CLIENT CODE COMEÇA AQUI!!
// ================================================================================

// Definições gerais
using Compare = bool (*)( const void *, const void * );
using byte = unsigned char;

/*!
 * Recebe dois estudantes e retorna true se eles tem o mesmo nome.
 */
bool
compareByName( const Student & _a, const Student & _b )
{
    return( _a.name == _b.name );
}

bool
compareByMedia ( const Student & _a, const Student & _b )
{
    auto media_a = (_a.grades[0] + _a.grades[1] + _a.grades[2]) / 3.0;
    auto media_b = (_b.grades[0] + _b.grades[1] + _b.grades[2]) / 3.0;
    
    return media_a < media_b;
}

bool
predBySemester ( const Student & _a)
{
	return (_a.year % 10 != 2); 
}

bool
predReposition (const Student & _a)
{
	return (_a.grades[0] < 3.0 || _a.grades[1] < 3.0 || _a.grades[2] < 3.0);
}



/**!
 *  Procura por um valor dentro de um intervalo [first_;last_).
 *  @param first_ Inicio do intervalo de busca (inclusive).
 *  @param last_ Final do intervalo de busca (exclusive).
 *  @param cmp_ Ponteiro para função de comparação que retorna true se dois elementos são iguais.
 *  @param val_ Elemento procurado no intervalo.
 *  @return iterador para o elemento procurado, ou last_, se não encontrar.
 */



template < typename FwrdIt, typename Comparator, typename T >
FwrdIt
Find( FwrdIt first_, FwrdIt last_, Comparator cmp_, T val_ )
{
    for ( /* empty */ ; first_ != last_ ; ++first_ )
        if ( cmp_( *first_, val_ ) == 0 ) break;

    return first_;
}




template < typename FwrdIt , typename UnaryPredicate >
FwrdIt
Find_If ( FwrdIt first_ , FwrdIt last_ , UnaryPredicate p )
{
	for ( /* empty*/ ; first_ != last_ ; ++first_)
		if ( p( *first_ ) ) break;
	return first_;
}




template < typename FwrdIt , typename Compare >
FwrdIt
Min ( FwrdIt first_ , FwrdIt last_ , Compare cmp )
{
	FwrdIt smaller = first_;
	for ( /* empty*/ ; first_ != last_ ; ++first_)
		if ( cmp( *first_, *smaller ) )
			smaller = first_;
	return smaller;
}




template < typename InputIt , typename OutputIt >
OutputIt 
Copy ( InputIt first_ , InputIt last_ , OutputIt d_first )
{
	int aux = 0;
	for (; first_ != last_ ; ++first_)
	{
		*(d_first + aux++) = *first_;
	}

	return (d_first + aux);
}





template < typename FwrdIt , typename UnaryPredicate >
FwrdIt
Remove_If ( FwrdIt first_ , FwrdIt last_ , UnaryPredicate p )
{
	for ( /* empty */; first_ != last_; first_++)
	{
		if ( p( *first_ ) )
		{
			FwrdIt tmp_ = first_ + 1;
			while (tmp_ != last_)
			{
				*tmp_ = *(tmp_ + 1);
				tmp_++;
			}
			last_--;
		}
	}
	return last_;
}






template < typename FwrdIt , typename Compare >
FwrdIt
Unique ( FwrdIt first_ , FwrdIt last_ , Compare cmp )
{
	for ( /* empty*/ ; first_ != last_; first_++)
	{
		auto aux_ = first_ + 1;
        for ( /* empty */; aux_ != last_; aux_++)
        {
            if (compareByName(*aux_, *first_))
            {
                auto aux_2_ = aux_ + 1;
                for (/* empty */; aux_2_ != last_; aux_2_++)
                    *aux_2_ = *(aux_2_ + 1);
                last_--;
            }
        }

	}
	return last_;
}






int main( )
{
    // Lista de estudantes para teste.
    Student arr[] = { { "Leonidas" ,  7.5, 3.2, 6.7, 20142 },
                      { "Musashi"  ,  9.5, 8.2, 8.7, 20131 },
                      { "Spartacus",  2.1, 3.5, 5.5, 20123 },
                      { "Miltiades",  0.1, 5.6, 4.4, 20151 },
                      { "Aquiles"  ,  6.5, 7.1, 8.6, 20141 },
                      { "Thor"     ,  4.5, 6.2, 2.1, 20132 },
                      { "Lancelot" ,  6.5, 6.0, 7.4, 20122 },
                      { "Miltiades",  2.1, 6.6, 4.7, 20131 }
    };
    // Número de estudantes na lista.
    const auto arrSz = sizeof( arr ) / sizeof( *arr );

    // Imprime a lista na tela.
    std::cout << ">>> Data array:\n";
    for( const auto &e : arr )  std::cout << e << "\n";
    std::cout << "\n";


    //================================================================================
    // I. Utilizando find.
    //--------------------------------------------------------------------------------
    
    // Procurando por elementos no arranjo.
    auto target( arr[4] ); // Procurando elemento que está na posição 4 do vetor.
    auto resp = Find( std::begin(arr), std::end(arr), compareByName, target );
    auto location = std::distance( std::begin(arr), resp ); // Posicao

    // Se resultado for diferente do final do vetor, quer dizer que achou!
    if ( resp != std::end(arr) )
        std::cout << ">>> Student " << target
                  << " found at position " << location
                  << std::endl;
    else
        std::cout << ">>> Sorry, warrior " << target << " not found!\n\n";

    // Nova busca com um elemento que não está na lista.
    target = Student( "Alatriste", 5.5, 10.0, 9.3, 20141 );
    resp = Find( std::begin(arr), std::end(arr), compareByName, target );
    location = std::distance( std::begin(arr), resp );
    if ( resp != std::end(arr) )
        std::cout << ">>> Student " << target
                  << " found at position " << location
                  << std::endl;
    else
        std::cout << ">>> Sorry, student " << target << " not found!\n\n";





    //================================================================================
    // II. Utilizando Min.
    //--------------------------------------------------------------------------------
    auto min_grade = Min( std::begin(arr), std::end(arr), compareByMedia);
	auto media = (min_grade->grades[0] + min_grade->grades[1] + min_grade->grades[2]) / 3.0;
	std::cout << "\n\n>>> Aluno com menor media: " << min_grade->name << std::endl;
	std::cout << ">>> Media do aluno: " << media << std::endl;

	auto alunoRep = Find_If(std::begin(arr), std::end(arr), predReposition);
    std::cout << "\n\n>>> O primeiro aluno que esta em reposicao eh: " << alunoRep->name << std::endl;


    //================================================================================
    // III. Utilizando Copy & Unique.
    //--------------------------------------------------------------------------------
    
    // Criando uma lista vazia com mesmo nome que a lista original.
    
    Student arrCopy[ arrSz ];
    auto beginCopy = std::begin(arrCopy);
    auto endCopy = Copy(std::begin(arr), std::end(arr), beginCopy);
    auto newEndCopy = Unique(beginCopy, endCopy, compareByName);


    std::cout << "\n\n>>> Lista de nomes de alunos sem repetições de nome: " << std::endl;
    for (/* empty */; beginCopy != newEndCopy; beginCopy++)
        std::cout << beginCopy->name << std::endl;
	

    //================================================================================
    // IV. Copy & Remove_If 
    //--------------------------------------------------------------------------------
    
    
    
    //================================================================================
    // IV. Copy & Remove_If 
    //--------------------------------------------------------------------------------
    
    /*
    
    TO DO
    
    
    Student arrSemester[ arrSz ];
    auto arrEnd = Remove_If(std::begin(arr), std::end(arr), predBySemester);
    arrEnd = Copy(std::begin(arr), std::end(arr), std::begin(arrSemester));
	auto beginSemester = std::begin(arrSemester);


	for ( ; beginSemester != arrEnd; beginSemester++)
		std::cout << beginSemester->name << std::endl;
	
	
	*/
	
    std::cout << "\n\n>>> Normal exiting...\n";

    return EXIT_SUCCESS;
}
