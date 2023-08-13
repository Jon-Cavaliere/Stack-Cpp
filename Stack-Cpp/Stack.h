#pragma once
#include <stdint.h>
#include <cmath>
#include <iostream>
#include <stdexcept>

/**
	Implementation of a simple class template stack data structure on the heap
	Author: Jonathan Cavaliere, 2023
	Free to use for any purpose! 
*/

namespace JC
{
	// Declaration
	template <typename T>
	class Stack
	{
	public:
		/* Constructor
		* @param initial_size - amount of element slots allocated (before growing)
		* @param growth_factor - multiplier for size growth when resize occurs
		*/
		Stack<T>(uint32_t initial_size, float growth_factor = 2.0f);
		~Stack<T>();
		void push(T obj);					// Pushes an element to the top of the stack
		T pop();						// Pops the top element off the stack, returns a copy
		void resize(uint32_t new_size);				// Resizes the array, moves all the elements over
		uint32_t count();					// Returns # of elements on stack
		T* get(uint32_t index);					// Returns a pointer to element at index 
		void set(uint32_t index, T val);			// Sets the value of elemnt at index
		bool hasNext();						// Returns true if stack has elements

		void print();						// Dumps entire contents of stack to console (oldest -> most recently pushed)

	private:
		// Heap allocated array of T objects to store
		T* p_Arr;
		// Currently allocated size
		uint32_t m_Size;
		// Currently filled slots of the array (Number of elements)
		uint32_t m_Count;
		// Pointer to the top of the stack
		T* p_Top;
		// Growth factor (Multiplier for array size when resize occurs)
		float m_GrowthFactor;
	};

	// Definitions
	template <typename T>
	inline Stack<T>::Stack(uint32_t initial_size, float growth_factor)
		: m_Size(initial_size), m_Count(0), m_GrowthFactor(growth_factor)
	{
		p_Arr = new T[initial_size];
	}

	template<typename T>
	inline Stack<T>::~Stack()
	{
		// Deallocate array
		delete[] p_Arr;
	}

	template <typename T>
	inline void Stack<T>::push(T obj)
	{
		// Check if stack has enough space to add element
		if (m_Count+1 <= m_Size)
		{
			// If it does, add it
			p_Arr[m_Count++] = obj;
		}
		else
		{
			// If not, reallocate, copy array, then add it (default grows by 2x)
			uint32_t new_size = std::lrint(m_Size * m_GrowthFactor);
			resize(new_size);
			p_Arr[m_Count++] = obj;
		}
	}

	template <typename T>
	inline T Stack<T>::pop() { return p_Arr[--m_Count]; }

	template <typename T>
	inline void Stack<T>::resize(uint32_t new_size)
	{
		// Create temporary array of new_size size
		T* newArr = new T[new_size];
		// Iterate through old array and copy everything over
		for (int i = 0; i < m_Count; i++)
			newArr[i] = p_Arr[i];
		// Delete old array
		delete[] p_Arr;
		// Allocate new array and copy it over... again. 
		p_Arr = new T[new_size];
		for (int i = 0; i < m_Count; i++)
			p_Arr[i] = newArr[i];
		delete[] newArr; // Delete temporary new array
		// Growth complete	
	}

	template<typename T>
	inline uint32_t Stack<T>::count(){ return m_Count; }

	template<typename T>
	inline T* Stack<T>::get(uint32_t index)
	{
		// If index is within bounds of array
		if (index <= m_Count)
			return &p_Arr[index];
		// Else throw exception
		throw std::out_of_range("Stack::get() Index out of stack bounds");
		return nullptr; // Definitely unreachable code
	}

	template<typename T>
	inline void Stack<T>::set(uint32_t index, T val)
	{
		// Check if index is valid
		if(index < m_Size)
			p_Arr[index] = val;
		// If not throw out of range exception
		else
			throw std::out_of_range("Stack::set() Index out of stack bounds");
	}

	template<typename T>
	inline bool Stack<T>::hasNext()
	{
		// Check if number of current elements is > 0
		if (m_Size > 0)
			return true;
		// If not, no next :)
		return false;
	}

	template<typename T>
	inline void Stack<T>::print()
	{
		// For proper printing ensure that any classes used with this have overloaded << operator
		for (int i = 0; i < m_Count; i++)
			std::cout << p_Arr[i] << "\n";
	}
}
