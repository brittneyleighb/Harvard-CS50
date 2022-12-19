SELECT AVG(ratings) FROM ratings
JOIN movies ON ratings.movie_id = movies.id
WHERE year = 2021;