select avg(rating) from ratings where movie_id = (
    select id from movies where year = 2012
);
