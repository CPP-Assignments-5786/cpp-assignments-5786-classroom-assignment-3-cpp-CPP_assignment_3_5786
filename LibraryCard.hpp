/**
 * @file LibraryCard.hpp
 * @brief Header file for the LibraryCard class
 *
 * This file demonstrates: 
 * - Composition (LibraryCard HAS-A Book array)
 * - Dynamic arrays with destructors (destruct-arrays)
 * - Reference parameters
 * - Const methods
 * - Static members
 * - Inline/Outline implementations
 */

#ifndef LIBRARYCARD_HPP
#define LIBRARYCARD_HPP

#include "Book.hpp"
#include <string>
#include <iostream>

namespace library {

    /**
     * @brief LibraryCard class for managing borrowed books
     * Demonstrates: composition, destruct-arrays, reference parameters
     */
    class LibraryCard {
    private:
        std::string memberName;
        std::string memberID;
        Book** borrowedBooks;      // COMPOSITION: Dynamic array of Book pointers
        int capacity;
        int borrowCount;
        
        // Static member: track total cards issued
        static int totalCardsIssued;

        /**
         * @brief Helper to resize the borrowed books array
         */
        void resize();

    public:
        // ============ Constructors ============

        /**
         * @brief Default constructor
         * Creates card for "Guest" with capacity 3
         */
        LibraryCard();

        /**
         * @brief Parameterized constructor
         * @param memberName Member's name
         * @param memberID Member ID
         * @param initialCapacity Initial capacity for books (default 3)
         */
        LibraryCard(const std::string& memberName, const std::string& memberID, 
                   int initialCapacity = 3);

        /**
         * @brief Copy constructor - deep copy
         * @param other Card to copy from
         */
        LibraryCard(const LibraryCard& other);

        /**
         * @brief Destructor
         * Must properly delete the dynamic array of Book pointers
         */
        ~LibraryCard();

        // ============ Getters - Inline implementations ============

        /**
         * @brief Get member name - const method
         * @return Member name
         */
        inline std::string getMemberName() const {
            return memberName;
        }

        /**
         * @brief Get member ID - const method
         * @return Member ID
         */
        inline std::string getMemberID() const {
            return memberID;
        }

        /**
         * @brief Get number of borrowed books - const method
         * @return Borrow count
         */
        inline int getBorrowCount() const {
            return borrowCount;
        }

        /**
         * @brief Get capacity - const method
         * @return Current capacity
         */
        inline int getCapacity() const {
            return capacity;
        }

        /**
         * @brief Check if card is full - const method
         * @return true if no more books can be borrowed
         */
        inline bool isFull() const {
            return borrowCount >= capacity;
        }

        // ============ Setters - Outline implementations ============

        /**
         * @brief Set member name
         * @param name New name
         */
        void setMemberName(const std::string& name);

        // ============ Static methods ============

        /**
         * @brief Get total cards issued
         * @return Total cards issued
         */
        static int getTotalCardsIssued();

        // ============ Book management - Reference parameters ============

        /**
         * @brief Borrow a book (adds to borrowed list)
         * @param book Reference to the book to borrow
         * @return true if successful, false if card is full
         */
        bool borrowBook(const Book& book);

        /**
         * @brief Return a book by index
         * @param index Index of book to return
         * @return true if successful
         */
        bool returnBook(int index);

        /**
         * @brief Return a book by title
         * @param title Title of book to return
         * @return true if found and returned
         */
        bool returnBook(const std::string& title);

        /**
         * @brief Find a borrowed book - const method
         * @param title Title to search for
         * @return Pointer to book if found, nullptr otherwise
         */
        Book* findBorrowedBook(const std::string& title) const;

        /**
         * @brief Get total pages of all borrowed books - const method
         * @return Total pages
         */
        int getTotalBorrowedPages() const;

        /**
         * @brief Print all borrowed books - const method
         */
        void printBorrowedBooks() const;

        /**
         * @brief Print card details to stream
         * NOT operator overloading - just a regular method
         * @param os Output stream
         */
        void print(std::ostream& os) const;

        /**
         * @brief Clear all borrowed books
         */
        void clear();

        // ============ Friend functions ============

        /**
         * @brief Compare two cards by borrow count
         * @param c1 First card
         * @param c2 Second card
         * @return true if c1 has more borrowed books
         */
        friend bool compareByBorrowCount(const LibraryCard& c1, const LibraryCard& c2);
    };

} // namespace library

#endif // LIBRARYCARD_HPP