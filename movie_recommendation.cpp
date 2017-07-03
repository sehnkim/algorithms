// prob2.
// https://gist.github.com/elliatab/be492805b3af6a9ac244

//Implement a function to return top rated movies in the network of movies reachable from the current movie.
//
//
//* eg.A(Rating 1.2)
//* / \
//*            B(2.4)  C(3.6)
//*              \ /
//*D(4.8)
//In the above example, edges represent similarity and the number is rating.
//* getMovieRecommendations(A, 2) should return C and D(sorting order doesn't matter so it can also return D and C) 
//	* getMovieRecommendations(A, 4) should return A, B, C, D(it can also return these in any order eg : B, C, D, A)
//	* getMovieRecommendations(A, 1) should return D.Note distance from A to D doesn't matter, return the highest rated.
//
//
//	import java.util.ArrayList;
//import java.util.List;
//
//public class Movie {
//	private final int movieId;
//	private final float rating;
//	private List<Movie> similarMovies; // Similarity is bidirectional
//
//	public Movie(int movieId, float rating) {
//		this.movieId = movieId;
//		this.rating = rating;
//		similarMovies = new ArrayList<Movie>();
//	}
//
//	public int getId() {
//		return movieId;
//	}
//
//	public float getRating() {
//		return rating;
//	}
//
//	public void addSimilarMovie(Movie movie) {
//		similarMovies.add(movie);
//		movie.similarMovies.add(this);
//	}
//
//	public List<Movie> getSimilarMovies() {
//		return similarMovies;
//	}
//
//	/*  *
//	*     @param movie
//	*     @param numTopRatedSimilarMovies
//	*                      number of movies we want to return
//	*     @return List of top rated similar movies
//	*/
//	public static List<Movie> getMovieRecommendations(Movie movie, int numTopRatedSimilarMovies) {
//		// Implement me
//		return null;
//	}
//}

#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <stack>
#include <unordered_map>	// unordered_map<int, int> hash;
							// vector<int>::iterator itr;

#include <set>
using namespace std;

class Movie {
public:
	int movieId;
	float rating;
	vector<Movie*> similarMovies; // Similarity is bidirectional

	Movie(int movieId, float rating) 
	{
		this->movieId = movieId;
		this->rating = rating;
		this->similarMovies = vector<Movie*>();
	}

	int getId() {
		return movieId;
	}

	float getRating() {
		return rating;
	}

	void addSimilarMovie(Movie& movie) {
		this->similarMovies.push_back(&movie);
		movie.similarMovies.push_back(this);
	}

	vector<Movie*> getSimilarMovies() {
		return similarMovies;
	}
};


//bool operator > (const Movie& a, const Movie& b) 
//{
//	return a.getRating() > b.getRating();
//}

struct classcomp
{
	bool operator() (Movie* lhs, Movie* rhs) const
	{
		return lhs->getRating() > rhs->getRating();
	}
};

void getMovieRecommendationsRec(Movie& movie, int N, set<Movie*>& s)
{
	vector<Movie*> movies;

	// For each movie, get similar movies.
	for (Movie* m : movie.getSimilarMovies())
	{
		if (m == &movie)
			continue;

		// if the movie is not the same.
		if (s.find(m) == s.end())
		{
			s.insert(m);
			getMovieRecommendationsRec(*m, N, s);
		}
	}
}


vector<Movie*> getMovieRecommendations(Movie &movie, int N)
{
	vector<Movie*> movies;
		
	if (N == 0)
		return movies;

	if (N > 0) {
		set<Movie*> s;
		getMovieRecommendationsRec(movie, N, s);
		
		cout << "movie count:" << s.size() << endl;
		vector<Movie*> vec;
		sort(vec.begin(), vec.end(), classcomp());

		for (Movie* m : s)
			cout << "Movie id=" << m->getId() << " Rating=" << m->getRating() << endl;
	}

	return movies;
}


//ABBBC --> A4XBC
//
//  i
//A A B B B C
//
//prev: A
//cur : A
//count: 2 
string encode(const string& str)
{
	string output("");
	char prev = str[0];
	char cur = str[1];
	int size = str.size();
	int count = 1;


	for (int i=1; i<size+1; ++i)
	{
		// if c is the end of the string.
		if (i == size) {
			string temp;
			if (count == 1)
				temp = cur;
			else
				// need to encode and append it to the output.
				temp = to_string(count) + "X" + cur; // 3XB
			output += temp;  // 2XA3XB
		}
		else {

			cur = str[i];
			// if c (cur) is the same as prev.
			if (cur == prev) {
				++count;
			}
			// if c is not the same as prev.
			else if (cur != prev) {
				string temp;
				if (count == 1)
					temp = prev;
				else
					// need to encode and append it to the output.
					temp = to_string(count) + "X" + prev; // 3XB
				output += temp;  // 2XA3XB

				// Resets the vars. 
				count = 1;
				prev = cur;	// C
			}
		}
	}

	return output;

}

struct node
{
	int d;
	node* next;
	node* rand;

	node(int data) : d(data), next(NULL), rand(NULL) {}
};

node* DeepCopy(node* head)
{
	node* n = head;

	// for each node,
	unordered_map<node*, node*> hash;

	while (n != NULL) {
		node* copy = new node(n->d);
		hash[n] = copy;
		n = n->next;
	}
	n = head;

	node* clone = NULL;
	while (n != NULL) {
		clone = n;
		clone->next = n->next;
		clone->rand = hash[n];
		n = n->next;
	}
	return clone;
}




void main()
{
	std::unordered_map<int, int> map;
	map[-1] = 3;
	cout << map[-1];

	//Movie movieA(1, 3.2f);
	//Movie movieB(2, 2.4f);
	//Movie movieC(3, 1.6f);
	//Movie movieD(4, 4.8f);

	//movieA.addSimilarMovie(movieB);
	//movieA.addSimilarMovie(movieC);

	//movieB.addSimilarMovie(movieA);
	//movieB.addSimilarMovie(movieD);
	//
	//movieC.addSimilarMovie(movieA);
	//movieC.addSimilarMovie(movieD);
	//
	//movieD.addSimilarMovie(movieB);
	//movieD.addSimilarMovie(movieC);

	//for (Movie* m : getMovieRecommendations(movieA, 2)) {
	//	//cout << "Movie id=" << m->getId() << " Rating=" << m->getRating() << endl;
	//}

	//char c = 'a';
	//char d = 'b';
	//swap(c, d);
	//cout << c << " " << d << endl;

	////string test("test");
	////cout << test;

	////cout << encode("AABBBC");

	//// deep copy

}











