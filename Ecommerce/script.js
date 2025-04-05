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

  // --- Code to fetch and display average rating and count ---
  productContainers.forEach(product => {
      // Assuming your HTML has a way to identify each product uniquely
      const productId = product.querySelector('h3') ? product.querySelector('h3').textContent.replace(/\s+/g, '-').toLowerCase() : 'default-id'; // Example: using product title as a basic ID
      // **Important:** Replace the above line with a reliable way to get a unique product ID from your HTML or data

      fetchRatingData(productId)
          .then(data => {
              const ratingCountSpan = product.querySelector('.rating-count');
              const averageRatingSpan = product.querySelector('.average-rating');
              const stars = product.querySelectorAll('.star');
              const average = data.average_rating;
              const count = data.rating_count;

              if (ratingCountSpan) {
                  ratingCountSpan.textContent = count;
              }
              if (averageRatingSpan) {
                  averageRatingSpan.textContent = average ? average.toFixed(1) : '0'; // Handle cases with no ratings
              }

              // Update star visuals based on the fetched average rating
              stars.forEach((star, index) => {
                  star.classList.remove('filled'); // Reset filled state
                  if (average && index < Math.floor(average)) {
                      star.classList.add('filled');
                  } else if (average > index && average < index + 1) {
                      // You might want to add a class for partially filled stars here
                      // For simplicity, this example only fills whole stars
                  }
              });
          });
  });

  // --- Code for user interaction with stars ---
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

          // Initial rendering of the rating for each product (based on data-rating attribute)
          const initialRating = parseInt(productDiv.getAttribute('data-rating'));
          stars.forEach(s => {
              if (parseInt(s.getAttribute('data-value')) <= initialRating) {
                  s.classList.add('active');
              }
          });
      }
  });

  // Dummy function - replace with your actual API call
  function fetchRatingData(productId) {
      // In a real application, you would make an API call here
      return new Promise(resolve => {
          // Simulate fetching data
          setTimeout(() => {
              const fakeData = {
                  'charming-heart-necklace': { average_rating: 4.2, rating_count: 12 }, // Example ID based on title
                  // ... more product data using a consistent ID scheme
              };
              resolve(fakeData[productId] || { average_rating: 0, rating_count: 0 });
          }, 200);
      });
  }
});