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
    const ratingContainer = document.querySelector('.product .rating'); // Assuming one product for now
    const stars = ratingContainer.querySelectorAll('.star');
    const productDiv = ratingContainer.closest('.product'); // Get the parent product div
  
    if (ratingContainer) {
      stars.forEach(star => {
        star.addEventListener('click', function() {
          const ratingValue = parseInt(this.getAttribute('data-value'));
  
          // Update the visual representation of the rating
          stars.forEach(s => {
            if (parseInt(s.getAttribute('data-value')) <= ratingValue) {
              s.classList.add('active');
            } else {
              s.classList.remove('active');
            }
          });
  
          // Optionally update the data-rating attribute of the product
          if (productDiv) {
            productDiv.setAttribute('data-rating', ratingValue);
            console.log(`User rated this product: ${ratingValue} stars`);
  
            // --- Here you would typically send the rating to your server ---
            // You would likely use an AJAX request (fetch or XMLHttpRequest)
            // to send the 'ratingValue' and the 'product ID' to your backend.
            // Example (conceptual):
            /*
            fetch('/api/rate-product', {
              method: 'POST',
              headers: {
                'Content-Type': 'application/json',
              },
              body: JSON.stringify({
                productId: getProductId(productDiv), // You'd need a way to identify the product
                rating: ratingValue
              }),
            })
            .then(response => response.json())
            .then(data => {
              console.log('Rating saved:', data);
              // Optionally update the UI based on the server response
            })
            .catch(error => {
              console.error('Error saving rating:', error);
            });
            */
          }
        });
  
        star.addEventListener('mouseover', function() {
          const hoverValue = parseInt(this.getAttribute('data-value'));
          stars.forEach(s => {
            if (parseInt(s.getAttribute('data-value')) <= hoverValue) {
              s.classList.add('hover');
            } else {
              s.classList.remove('hover');
            }
          });
        });
  
        star.addEventListener('mouseout', function() {
          stars.forEach(s => {
            s.classList.remove('hover');
          });
          // Re-apply active class based on the current data-rating (if needed)
          const currentRating = parseInt(productDiv.getAttribute('data-rating'));
          stars.forEach(s => {
            if (parseInt(s.getAttribute('data-value')) <= currentRating) {
              s.classList.add('active');
            } else {
              s.classList.remove('active');
            }
          });
        });
      });
  
      // Initial rendering of the rating based on the data-rating attribute
      const initialRating = parseInt(productDiv.getAttribute('data-rating'));
      stars.forEach(s => {
        if (parseInt(s.getAttribute('data-value')) <= initialRating) {
          s.classList.add('active');
        }
      });
    }
  });
  
  // Helper function (you'll need to implement this based on your HTML structure)
  function getProductId(productElement) {
    // Example: If you have a data-product-id attribute
    // return productElement.getAttribute('data-product-id');
    // Or if the ID is part of a class or another element
    // ... your logic to extract the product ID ...
    return 'product-123'; // Placeholder
  }