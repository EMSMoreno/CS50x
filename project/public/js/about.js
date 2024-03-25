let movie_id = location.pathname;

// fetching movie details
fetch(
  `${movie_detail_http}${movie_id}?` +
    new URLSearchParams({
      api_key: api_key,
    })
)
  .then((res) => res.json())
  .then((data) => {
    setupMovieInfo(data);
  });
/*In here, I extracted the movie ID from the current location's pathname
  dynamically. It fetch detailed info about the movie using the database API
  and the provided movie ID*/

const setupMovieInfo = (data) => {
  const movieName = document.querySelector(".movie-name");
  const genres = document.querySelector(".genres");
  const des = document.querySelector(".des");
  const title = document.querySelector("title");
  const backdrop = document.querySelector(".movie-info");

  title.innerHTML = movieName.innerHTML = data.title;
  genres.innerHTML = `${data.release_date.split("-")[0]} | `;
  for (let i = 0; i < data.genres.length; i++) {
    genres.innerHTML +=
      data.genres[i].name + formatString(i, data.genres.length);
  }

  /*This function takes the movie data retrieved from the api and updates the
  content of the specific html elements on the page to display details about that 
  certain movie you chose, such as title, genre, release date and many other info*/

  if (data.adult == true) {
    genres.innerHTML += " | +18";
  }

  if (data.backdrop_path == null) {
    data.backdrop_path = data.poster_path;
  }

  /* checks if the movie is marked as adult content and pass the true condition
  if that content is 18+*/

  des.innerHTML = data.overview.substring(0, 200) + "...";

  backdrop.style.backgroundImage = `url(${original_img_url}${data.backdrop_path})`;
};

const formatString = (currentIndex, maxIndex) => {
  return currentIndex == maxIndex - 1 ? "" : ", ";
};

//fetching cast info

fetch(
  `${movie_detail_http}${movie_id}/credits?` +
    new URLSearchParams({
      api_key: api_key,
    })
)
  .then((res) => res.json())
  .then((data) => {
    const cast = document.querySelector(".starring");
    for (let i = 0; i < 5; i++) {
      cast.innerHTML += data.cast[i].name + formatString(i, 5);
    }
  });

/*here I'm fetching info about the cast of a movie and updates the content 
  on the html element with the class starring to display names up to 5 members*/

// fetching video clips

fetch(
  `${movie_detail_http}${movie_id}/videos?` +
    new URLSearchParams({
      api_key: api_key,
    })
)
  .then((res) => res.json())
  .then((data) => {
    let trailerContainer = document.querySelector(".trailer-container");

    let maxClips = data.results.length > 4 ? 4 : data.results.length;

    for (let i = 0; i < maxClips; i++) {
      trailerContainer.innerHTML += `
        <iframe src="https://youtube.com/embed/${data.results[i].key}" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
        `;
    }
  });

/*here I'm fetching youtube trailers dynamically of that particular movie using
  a container called trailer-container */

// fetch recommendations

fetch(
  `${movie_detail_http}${movie_id}/recommendations?` +
    new URLSearchParams({
      api_key: api_key,
    })
)
  .then((res) => res.json())
  .then((data) => {
    let container = document.querySelector(".recommendations-container");
    for (let i = 0; i < 16; i++) {
      if (data.results[i].backdrop_path == null) {
        i++;
      }
      container.innerHTML += `
        <div class="movie" onclick="location.href = '/${data.results[i].id}'">
            <img src="${img_url}${data.results[i].backdrop_path}" alt="">
            <p class="movie-title">${data.results[i].title}</p>
        </div>
        `;
    }
  });

/*here I'm fetching movie recommendations based on the current movie and dynamically adds 
  up to 16 recommended movies to an html element with the class recommendations-container,
  much like above*/
