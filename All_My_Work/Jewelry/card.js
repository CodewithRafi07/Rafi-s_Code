window.onload = function () {
    const cart = JSON.parse(localStorage.getItem('cart')) || [];
    const container = document.getElementById('cart-items');

    if (cart.length === 0) {
        container.innerHTML = "<p>Your cart is empty.</p>";
    } else {
        cart.forEach(product => {
            const div = document.createElement('div');
            div.className = 'cart-item';
            div.innerHTML = `
                <img src="${product.image}" alt="${product.name}" />
                <div>
                    <h3>${product.name}</h3>
                    <p>${product.price}</p>
                </div>
            `;
            container.appendChild(div);
        });
    }
};
