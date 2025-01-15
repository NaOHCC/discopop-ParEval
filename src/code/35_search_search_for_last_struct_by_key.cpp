struct Book {
   std::string title;
   int pages;
};

/* Return the index of the last Book item in the vector books where Book.pages is less than 100.
	 Example:

   input: [{title="Green Eggs and Ham", pages=72}, {title="gulliver's travels", pages=362}, {title="Stories of Your Life", pages=54}, {title="Hamilton", pages=818}]
   output: 2
*/
NO_INLINE size_t findLastShortBook(std::vector<Book> const& books) {
size_t last_short_book_index = 0;
   for (size_t i = 0; i < books.size(); ++i) {
      if (books[i].pages < 100) {
         last_short_book_index = i;
      }
   }
   return last_short_book_index;
}