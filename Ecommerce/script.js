// Toggle between dark and light themes
function toggleTheme() {
    document.body.classList.toggle('dark');
}

// Add animations for page load
window.onload = () => {
    document.body.style.opacity = 1;
    document.body.style.transition = 'opacity 0.5s ease-in';
    document.body.style.opacity = 1;
};

document.addEventListener('DOMContentLoaded', function() {
    const productContainers = document.querySelectorAll('.product'); // Get ALL elements with the class 'product'
  
    productContainers.forEach(productDiv => {
      const ratingContainer = productDiv.querySelector('.rating'); // Find the .rating within the current product
      const stars = ratingContainer ? ratingContainer.querySelectorAll('.star') : []; // Get stars if rating exists
  
      if (ratingContainer) {
        stars.forEach(star => {
          star.addEventListener('click', function() {
            const ratingValue = parseInt(this.getAttribute('data-value'));
  
            const currentStars = this.parentNode.querySelectorAll('.star'); // Get stars in the current rating
            currentStars.forEach(s => {
              if (parseInt(s.getAttribute('data-value')) <= ratingValue) {
                s.classList.add('active');
              } else {
                s.classList.remove('active');
              }
            });
  
            productDiv.setAttribute('data-rating', ratingValue);
            console.log(`User rated product (potentially needs ID): ${ratingValue} stars`);
            // --- AJAX request to server would go here (needs product identification) ---
          });
  
          star.addEventListener('mouseover', function() {
            const hoverValue = parseInt(this.getAttribute('data-value'));
            const currentStars = this.parentNode.querySelectorAll('.star');
            currentStars.forEach(s => {
              if (parseInt(s.getAttribute('data-value')) <= hoverValue) {
                s.classList.add('hover');
              } else {
                s.classList.remove('hover');
              }
            });
          });
  
          star.addEventListener('mouseout', function() {
            const currentStars = this.parentNode.querySelectorAll('.star');
            currentStars.forEach(s => {
              s.classList.remove('hover');
            });
            const currentRating = parseInt(productDiv.getAttribute('data-rating'));
            currentStars.forEach(s => {
              if (parseInt(s.getAttribute('data-value')) <= currentRating) {
                s.classList.add('active');
              } else {
                s.classList.remove('active');
              }
            });
          });
        });
  
        // Initial rendering of the rating for each product
        const initialRating = parseInt(productDiv.getAttribute('data-rating'));
        stars.forEach(s => {
          if (parseInt(s.getAttribute('data-value')) <= initialRating) {
            s.classList.add('active');
          }
        });
      }
    });
  });