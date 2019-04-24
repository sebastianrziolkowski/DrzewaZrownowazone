# Wynik testow

![alt text](https://raw.githubusercontent.com/sebastianrziolkowski/DrzewaZrownowazone/master/DrzewaZrownowazone.bmp)


# Drzewa Zrownowazone

<p>
Zaimplementuj zbiór dynamiczny liczb całkowitych z operacjami dodawania
elementu do zbioru i wyszukiwania zadanego elementu. Operacja wyszukania
elementu zwraca informację o tym, czy element jest w zbiorze oraz liczbę
elementów w zbiorze mniejszych lub równych od zadanego.
</p>

<p>
Napisz program wykonujący zadane operacje na zbiorze. Program otrzymuje
kolejne zestawy operacji do wykonania. Każdy zestaw składa się z ciągu
operacji dodania elementu do zbioru i następującego po nim ciągu operacji
wyszukania. Przed wykonaniem pierwszego zestawu operacji zbiór jest pusty.
Każdy kolejny zestaw operuje na zbiorze powstałym przez wykonanie
poprzednich zestawów (elementy z kolejnych zestawów są dodawane do zbioru, ale żadne
nie są usuwane, ani zbiór nie jest opróżniany). Elementy, które należy
dodać do zbioru nie powtarzają się (także w różnych zestawach operacji). 
</p>

<h2>Wejście</h2>
<p>
W pierwszej linii wejścia znajduje się liczba <span class="math">z</span> 
(<span class="math">1 &le; z &le; 100000</span>) oznaczająca liczbę
zestawów danych.
W kolejnych <span class="math">2z</span> wierszach znajdują się
zestawy danych. Każdy zestaw składa się z dwóch wierszy. Pierwszy wiersz
zestawu zaczyna się od liczby <span class="math">m</span> (<span
class="math">0 &le; m &le; 500</span>). Po niej następuje <span
class="math">m</span> poprzedzonych spacją elementów, które należy dodać
do zbioru. Drugi wiersz
zestawu zaczyna się od liczby <span class="math">k</span> (<span
class="math">1 &le; k &le; 500</span>). Po niej następuje <span
class="math">k</span> poprzedzonych spacją elementów, które należy 
w zbiorze wyszukać. Elementy zbioru są liczbami całkowitymi nieujemnymi
nie większymi niż <span class="math">10000000</span>. 
<p>

<h2>Wyjście</h2>
<p>
Wyjście składa się z <span class="math">z</span> wierszy. Każdy wiersz
zawiera oddzielone spacją odpowiedzi na operacje wyszukiwania z
pojedynczego zestawu operacji. Odpowiedź taka składa się z dużej litery
<code>T</code> (element jest w zbiorze) lub <code>N</code> (elementu nie
ma w zbiorze), przecinka i liczby elementów w zbiorze mniejszych lub
równych od wyszukiwanego elementu. 
</p>

<h2>Przykład</h2>
<h3>Wejście</h3>
<pre>
3
1 10
3 5 10 15
3 15 20 30
3 15 18 20
4 1 2 3 8
3 5 10 15
</pre>

<h3>Wyjście</h3>
<pre>
N,0 T,1 N,1
T,2 N,2 T,3
N,3 T,5 T,6
</pre>

<h2>Warunki, które powinno spełniać rozwiązanie</h2>
<p>
Zbiór ma być zaimplementowany jako wariant drzewa BST (np. drzewo
czerwono-czarne lub drzewo AVL) taki, że
zarówno operacja wstawiania jak i operacja wyszukiwania (wraz z
obliczeniem liczby mniejszych lub równych elementów) powinna mieć
pesymistyczną złożoność czasową <span class="math">O(lg(n))</span>, gdzie
<span class="math">n</span> jest liczbą elementów zbioru.
</p>

<h2>Wskazówka</h2>
<p>
Węzły drzewa mogą zawierać, oprócz elementu zbioru i informacji potrzebnych np. do
zrównoważenia drzewa, także inne przydatne informacje.
</p>

Zadanie pochodzi z kursu uczelni UMCS
tichy.umcs.lublin.pl
