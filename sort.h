#include <iostream>
#include "BinaryTree.hpp"
using namespace std;


namespace sort {

	enum ORDER {
		ASC = 0,
		DSC = 1
	};

	template<class T>
	bool lt(T x, T y){
		return x < y;
	}

	template<class T>
	bool gt(T x, T y){
		return x > y;
	}

	template<class T>
	void printArr(T* arr, size_t len, size_t start = 0){
		for(size_t i = start; i < len; i++){
			cout << "[" << i << "]:\t" << arr[i] << endl;
		}
	}


	template<class T>
	void binarySort(T* arr, size_t len, ORDER ord = ASC){
		BinaryTree<T> bt(arr, len);
		bt.toArray(arr, ord);
	}

	template<class T>
	void selSort(T* arr, size_t len, ORDER ord = ASC){

		bool(*eval)(T, T);
		if(ord == ASC)
			eval = &gt<T>;
		else if(ord == DSC)
			eval = &lt<T>;

		for(size_t i = len -1; i > 0; i--){

			size_t target = 0;
			// Iterate from start till we reach current index
			for(size_t j = 1; j <= i; j++){
				if(eval(arr[j], arr[target]))
					target = j;
			}
			T temp = arr[i];
			arr[i] = arr[target];
			arr[target] = temp;

		}


	}

	template<class T>
	void bubbleSort(T* arr, size_t len, ORDER ord = ASC){
		bool(*eval)(T, T);
		if(ord == DSC)
			eval = &lt<T>;
		else if(ord == ASC)
			eval = &gt<T>;
		while(true){
			bool swapped = false;
			for(size_t i = 1; i < len; i++){
				if(eval(arr[i-1], arr[i])){
					T temp = arr[i];
					arr[i] = arr[i-1];
					arr[i-1] = temp;
					swapped = true;
				}
			}
			if(swapped == false) break;
		}
	}

	template<class T>
	void insertionSort(T* arr, size_t len, ORDER ord = ASC){
		bool(*eval)(T, T);
		if(ord == ASC)
			eval = &gt<T>;
		else if(ord == DSC)
			eval = &lt<T>;

		for(size_t i = 1; i < len; i++){
			size_t j = i;
			while(j > 0 && eval(arr[j - 1], arr[j])){
				T temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				j--;
			}
		}

	}

	template<class T>
	void quickSort(T* arr, size_t left, size_t right, ORDER ord = ASC){

		size_t i = left, j = right;
		T pivot = arr[(i+j) >> 1];
//		cout << "------------------------------------------------------------------\n";
//		cout << "Quicksort called between " << left << " and " << right << " with pivot " << pivot << endl;

		bool(*eval_i)(T, T);
		bool(*eval_j)(T, T);
		if(ord == DSC){
			eval_i = &gt<T>;
			eval_j = &lt<T>;
		}
		else if(ord == ASC){
			eval_i = &lt<T>;
			eval_j = &gt<T>;
		}

		while(i <= j){
			while(eval_i(arr[i], pivot))
				i++;
			while(eval_j(arr[j], pivot))
				j--;
			if(i <= j){
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				i++;
				j--;
			}
		}
//		printArr(arr, right + 1, left);
		if(i < right){
			quickSort(arr, i, right, ord);
		}
		if(j > left){
			quickSort(arr, left, j, ord);
		}
	}

	// Overload for keeping the interface uniform
	template<class T>
	void quickSort(T* arr, size_t len, ORDER ord = ASC){
		quickSort(arr, 0, len - 1, ord);
	}

};
