// Dark/Light theme toggle
const toggle = document.getElementById('theme-toggle');
if (toggle) { // Ensure the toggle element exists
    toggle.addEventListener('click', () => {
        document.body.classList.toggle('dark');
    });
}

// Scroll-based fade-in and slide-in
const faders = document.querySelectorAll('.fade-in, .slide-in');
const observer = new IntersectionObserver(entries => {
    entries.forEach(entry => {
        if (entry.isIntersecting) {
            entry.target.classList.add('visible');
        } else {
            // Optional: Remove 'visible' class when element is out of view
            // entry.target.classList.remove('visible');
        }
    });
});

// Observing each fader element
faders.forEach(fader => observer.observe(fader));

function addToCartAndRedirect(event) {
    const button = event.target;
    const productCard = button.closest('.product-card');

    if (productCard) {
        const nameElement = productCard.querySelector('.product-name');
        const priceElement = productCard.querySelector('.discounted-price');
        const imageElement = productCard.querySelector('img');

        if (nameElement && priceElement && imageElement) {
            const name = nameElement.innerText;
            const price = priceElement.innerText;
            const image = imageElement.getAttribute('src');

            // Get or initialize cart
            let cart = JSON.parse(localStorage.getItem('cart')) || [];

            // Add current product
            const newProduct = { name, price, image };
            cart.push(newProduct);

            // Save updated cart
            localStorage.setItem('cart', JSON.stringify(cart));

            // Redirect to add to cart page
            window.location.href = 'addtocart.html'; // Change to your actual page name
        } else {
            console.error("Missing product details.");
        }
    }
}

// Attach to all Add To Cart buttons
document.addEventListener('DOMContentLoaded', () => {
    const addCartButtons = document.querySelectorAll('.add-to-cart-button');
    addCartButtons.forEach(button => {
        button.addEventListener('click', addToCartAndRedirect);
    });
});


function goToCheckout(button) {
    const productCard = button.closest('.product-card');
    if (productCard) {
        const nameElement = productCard.querySelector('.product-name');
        const priceElement = productCard.querySelector('.product-price');
        const imageElement = productCard.querySelector('img');

        if (nameElement && priceElement && imageElement) {
            const name = nameElement.innerText;
            const price = priceElement.innerText;
            const image = imageElement.getAttribute('src');

            localStorage.setItem('productName', name);
            localStorage.setItem('productPrice', price);
            localStorage.setItem('productImage', image);

            window.location.href = 'checkout.html';
        } else {
            console.error("Could not find product name, price, or image in the product card.");
        }
    } else {
        console.error("Could not find the closest product card.");
    }}
// Note: The window.onload function for checkout logic should be in checkout.js