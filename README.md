# BOJ 문제풀이 코드
- 백준 온라인 저지의 문제풀이 코드 모음
___
## 1021번 회전하는 큐
>난이도: 실버 4  

#### 풀이
`deque`사용법을 익힐 수 있는 간단한 문제
- [문제 바로가기](https://www.acmicpc.net/problem/1021)
- [소스코드](https://github.com/choisb/baekjoon/tree/master/baekjoon/No_1021.cpp)

## 1269번 대칭 차집합
>난이도: 실버 4  

#### 풀이
1. A 집합의 원소를 모두 set에 저장

2. B 집합의 원소를 입력받으며 A에 존재 유무 탐색
   1. 이때 주의할 점은 이진탐색을 사용해야 한다는 점.
   1. `algorithm`의 `find`는 순차 탐색으로 최악의 경우 N의 시간이 걸리지만, `set`이 제공해주는 `find`는 logN시간을 보장.  

3. 존재한다면 `set`에서 원소 삭제, 존재하지 않는 다면 `set`에 원소 삽입

- [문제 바로가기](https://www.acmicpc.net/problem/1269)
- [소스코드](https://github.com/choisb/baekjoon/tree/master/baekjoon/No_1269.cpp)

## 1931번 회의실 배정
>난이도: 실버 2

#### 풀이
회의가 끝나는 시간을 기준으로 정렬하여서 계산하는 간단한 그리디 문제.
- [문제 바로가기](https://www.acmicpc.net/problem/1931)
- [소스코드](https://github.com/choisb/baekjoon/tree/master/baekjoon/No_1931.cpp)

## 2839번 설탕 배달
>난이도: 브론즈 1

#### 풀이
생략
- [문제 바로가기](https://www.acmicpc.net/problem/2839)
- [소스코드](https://github.com/choisb/baekjoon/tree/master/baekjoon/No_2839.cpp)
 
## 5052번 전화번호 목록
> 난이도: 실버 3  

#### 풀이
트라이를 이용한 풀이와 정렬 후 인접한 원소를 확인하는 두가지 방법이 존재.
여기서는 정렬 후 인접한 원소를 확인하는 방법으로 해결.

- [문제 바로가기](https://www.acmicpc.net/problem/5052)
- [소스코드](https://github.com/choisb/baekjoon/tree/master/baekjoon/No_5052.cpp)

## 5397번 키 로거
> 난이도: 실버 3  

#### 풀이
`list` 사용법을 익힐 수 있는 간단한 문제
- [문제 바로가기](https://www.acmicpc.net/problem/5397)
- [소스코드](https://github.com/choisb/baekjoon/tree/master/baekjoon/No_5397.cpp)

## 7785번 회사에 있는 사람
> 난이도: 실버 5  
#### 풀이
`set`을 익힐 수 있는 간단한 문제
- [문제 바로가기](https://www.acmicpc.net/problem/7785)
- [소스코드](https://github.com/choisb/baekjoon/tree/master/baekjoon/No_7785.cpp)

## 10546번 배부른 마라토너
> 난이도: 실버 4  
#### 풀이
`set`을 익힐 수 있는 간단한 문제
- [문제 바로가기](https://www.acmicpc.net/problem/10546)
- [소스코드](https://github.com/choisb/baekjoon/tree/master/baekjoon/No_10546.cpp)
