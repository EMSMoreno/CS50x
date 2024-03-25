const setupScrolling = () => {
  const containter = [...document.querySelectorAll(".movie-container")];
  const nxtBtn = [...document.querySelectorAll(".nxt-btn")];
  const preBtn = [...document.querySelectorAll(".pre-btn")];

  containter.forEach((item, i) => {
    let containerDimensions = item.getBoundingClientRect();
    let containerWidth = containerDimensions.width;

    nxtBtn[i].addEventListener("click", () => {
      item.scrollLeft += containerWidth;
    });

    preBtn[i].addEventListener("click", () => {
      item.scrollLeft -= containerWidth;
    });
  });
};

/* Created a function named setupScrolling to the the right
and left scrolling using event listeners, with two buttons, 
one for each position.
I select all the elements with the classes nxt and pre.btn, loop
through each movie container and add an event listener for each button.
*/
