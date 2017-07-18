## Complexity
* Tags: Hash map, Math
* Time Complexity: O(n^2)
* Space Complexity: O(1)

## Note
1. brute force 방법은 모든 경우를 다 고려해보는 것. 한 쌍의 점을 순서대로 택하고, 그 외의 점들이 그 쌍으로 이어진 선 위에 있는지 확인하는 것. 이렇게 하면 O^3의 복잡도.

2. 다른 방법은 D&C로 풀 수 있지 않을까 계속 고민하였는데 결국은 어떻게 divide를 해야 할지 몰라 좋은 방법이 아니라고 판별. 그렇다면 어떻게 해야 하는가?

3. 한 점을 중심으로 기울기가 같은 점들을 찾는다. 이는 결국 같은 한 점을 지나는 동일 선상의 위의 점들을 찾는것과 같은 것이다. 이렇게 해서 기울기를 찾았다면 x and y값에 대한 Greatest Common Divider를 hash map에 저장한다. unordered_map<unordered_map<int, int>, int> map; 로 저장하는데, 앞엣것은 GCD를 이용하여 기울기를 표현 한 것, 그리고 뒤의 int는 그 개수를 의미한다.

4. 이렇게 한 점을 중심으로 기울기가 동일한 것 중에 가장 큰 것을 찾는다. 그리고 이를 다른 점에 대해서도 동일하게 적용해서 그러면 결과중에 가장 큰 것을 찾는다.

5. 한가지 중요한 것은 x, y의 차이가 동일해서 duplicate point가 있을 수 있다는 것이다.

## Initial code
```

```

## Final code
```
int maxPoints(vector<Point> &points)
{
	if (points.size()<=2) return points.size();

	map<int,map<int,int> > map;
	int result=0;

	for (unsigned int i=0;i<points.size();i++){
		map.clear();
		int localmax=0,overlap=0;
		for (unsigned int j=i+1;j<points.size();j++){
			int x=points[j].x-points[i].x;
			int y=points[j].y-points[i].y;
			//check overlap
			if (x==0&&y==0){
				overlap++;
				continue;
			}
			int gcd=generateGCD(x,y);
			if (gcd!=0){
				x /= gcd;
				y /= gcd;
			}
			//find x,then y;
			int curr = ++map[x][y];
			localmax = max(curr, localmax);
		}
		result = max(result, localmax+overlap+1); // +1: point itself.
	}
	return result;
}

// Greatest Common Divider
int generateGCD(int a, int b)
{
	return b==0? a : generateGCD(b, a%b);
}
```
