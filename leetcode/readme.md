- [ ] key techniques
  - sliding window
  - two pointers
  - hashtable
  - DP
  - Greedy
  - backtracking
  - divide and conquer

- [ ] 25 Problems
  - Graph search: 3
  - DP: 2
  - binary tree: 8
  - sorting 응용: 3
  - 자료구조 어려운거 : 2
  - array에서 Greedy: 4
  - sliding window: 2
  - binary search 응용: 1
  - 10번 정도 폰인터뷰에서 나온 코딩 문제들 많은수는 소위 "two pointer" 문제. 알고리즘 지식보단 loop에서 한개 이상의 포인터를 갖고 놀수 있는지 코딩스킬을 테스트하는것. https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/#/description
  - "two pointer" 문제 좀더 어려운 버전: https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description … 보통 바깥 loop 안에 lo->hi, hi->lo 로 움직이는 loop이 두개 있는게 일반적.
  - pramp.com 으로 인터뷰 연습을 해보면, 나는 정답을 아는 상태에서 상대가 어떤 실수를 하는지 한눈에 알게된다. 거기에 나 자신을 투영하면 어떤 실수를 피해야 하는지 파악할수 있고.
  - https://github.com/checkcheckzz/system-design-interview … 시스템 디자인 인터뷰 팁 모음. 누군지 꼭 필요한 링크만 잘 모아놨다.
  - 오늘받은 인터뷰 질문 "브라우저에서 주소 입력하고 클릭하면 어떤 일들이 생기는지 설명해봐" 쉬운 질문이지만 os interrupt, tcp/ip, ssl, dns, 로드밸런싱 등등 떠들어야 할것이 많은 질문.
  - 오늘도 한 실수인데, 인터뷰가 시험이란 생각에 골몰하면 간단한 질문에도 '트릭이 뭘까?' 생각해 너무 심각한 솔루션을 내놓는다. Array로 해결될 문제를 redblack tree까지 😅
  - 문제가 어려워서 잘 못했다고 생각했는데, 정신줄 놓지않고 끈질기게 sub-optimal 답이라도 내놓은경우 온사이트를 받았다.
  - 코딩 인터뷰에서 제일 힘들땐 '이건 시험이다'라고 뇌가 인식할때. 특히 문제가 까다롭고 시간이 끝나가면 차분하게 해결할수 있는 문제도 뇌가 '시험이다 시험이다' 아득하게 외치기 시작하고 그럼 거의 잡힐듯하던 알고리즘도 멀어져간다. 그래서 pramp 같은 사이트의 모의 문제가 도움이 되는듯. 뇌가 문제 자체에만 집중하고 정신줄 잡아놓는 끈기를 훈련하는것.
  - 결과가 중립인 경우는 optimal 알고리즘을 몰라 brute force라도 정확하게 구현한 경우. 이건 글렀다 싶을때는 빨리 전략을 바꿔서 '중립' 점수라도 얻는게 낫다.


- [ ] review
  - [ ] 매일 3일
  - [ ] 1일 후
  - [ ] 2일 후
  - [ ] 1주일 후

while inside while vs. for

[Skiena's Algorithms Lectures](http://www3.cs.stonybrook.edu/~algorith/video-lectures/)


- [ ] web browser로 google.com에 접속했을때 운영체제, 네트워크에서 벌어지는 모든 일들을 설명해봐
- [ ] 프로그램이 execution될때 무슨 일이 일어나는지 Stack과 heap과 관련해서 설명해봐
- [ ] virtual memory 설명해봐
- [ ] Java가 C에 비해서 왜 느린지 설명해봐



- [ ] 297. Serialize and Deserialize Binary Tree [gitbub](297.Serialize_and_Deserialize_Binary_Tree/readme.md)  -  [leetcode](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/#/description)

- [ ] 149. Max Points on a Line [gitbub](149.Max_Points_on_a_Line/readme.md)  -  [leetcode](https://leetcode.com/problems/max-points-on-a-line/#/description)

- [ ] 230. Kth Smallest Element in a BST [gitbub](230.Kth_Smallest_Element_in_a_BST/readme.md)  -  [leetcode](https://leetcode.com/problems/kth-smallest-element-in-a-bst/#/description)

- [ ] 322. Coin Change [gitbub](322.Coin_Change/readme.md)  -  [leetcode](https://leetcode.com/problems/coin-change/#/description)

- [x] 236. Lowest Common Ancestor of a Binary Tree [gitbub](236.Lowest_Common_Ancestor_of_a_Binary_Tree/readme.md)  -  [leetcode](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/#/description)

- [x] 235. Lowest Common Ancestor of a Binary Search Tree [gitbub](235.Lowest_Common_Ancestor_of_a_Binary_Search_Tree/readme.md)  -  [leetcode](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/#/description)

- [x] 445. Add Two Numbers II
[gitbub](445.Add_Two_Numbers_II/readme.md)  -  [leetcode](https://leetcode.com/problems/add-two-numbers-ii/#/description)

- [ ] meeting-rooms

- [x] 56. Merge Intervals
[gitbub](056.Merge_Intervals/readme.md)  -  [leetcode](https://leetcode.com/problems/merge-intervals/#/description)

- [x] 152. Maximum Product Subarray
[gitbub](152.Maximum_Product_Subarray/readme.md)  -  [leetcode](https://leetcode.com/problems/maximum-product-subarray/#/description)

- [x] 53. Maximum Subarray
[gitbub](053.Maximum_Subarray/readme.md)  -  [leetcode](https://leetcode.com/problems/maximum-subarray/#/description)

- [x] 283. Move Zeroes
[gitbub](283.Move_Zeroes/readme.md)  -  [leetcode](https://leetcode.com/problems/move-zeroes/#/description)

- [x] 14. Longest Common Prefix
[gitbub](014.Longest_Common_Prefix/readme.md)  -  [leetcode](https://leetcode.com/problems/longest-common-prefix/#/description)

- [x] 3. Longest Substring Without Repeating Characters
[gitbub](003.Longest_Substring_Without_Repeating_Characters/readme.md)  -  [leetcode](https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description)
