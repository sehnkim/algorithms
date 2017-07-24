# algorithms


std::vector<int> v{0, 1, 2, 3, 4};
auto result1 = std::find(std::begin(v), std::end(v), n1);


hash.find(key)

std::unordered_map<std::string,double>::const_iterator got = mymap.find (input);
  if ( got == mymap.end() )
    std::cout << "not found";
  else
    std::cout << got->first << " is " << got->second;

<<<<<<< Local Changes
  std::cout << std::endl;
=======
  std::cout << std::endl;


func        | set         | hash        | string
----        |  --         | -----       | ---------
find        | O(log(n))   | O(1)        | O(m x n) *
substr      |             | xxx         |
size        |             | xxx         | O(1)
max_size    |             | xxx         | O(1)
operator [] |             | xxx         | O(1)
swap        |             | xxx         | O(1)
c_str       |             | xxx         | O(1)
data        |             | xxx         | O(1)

* string::find: KMP - O(m+n), but for std, it is not using KMP 아마도 메모리 할당, 그로인한 시간 낭비, 보통의 경우 partial match가 많이 없고, 문자의 길이가 그렇게 길지 않기 때문.
* 하나의 문자에 대해서는 O(n) since m=1.

>>>>>>> External Changes
