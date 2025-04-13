const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');

const app = express();
const port = 3000;

// Connect to MongoDB
mongoose.connect('mongodb://localhost:27017/dashboard', { useNewUrlParser: true, useUnifiedTopology: true });

// Define schemas
const visitorSchema = new mongoose.Schema({ visits: Number });
const cartSchema = new mongoose.Schema({ productName: String, quantity: Number });
const orderSchema = new mongoose.Schema({ productName: String, user: String, total: Number });

// Models
const Visitor = mongoose.model('Visitor', visitorSchema);
const Cart = mongoose.model('Cart', cartSchema);
const Order = mongoose.model('Order', orderSchema);

// Middleware
app.use(bodyParser.json());

// Routes
app.post('/save-visitor-count', async (req, res) => {
  const visitor = new Visitor({ visits: req.body.visits });
  await visitor.save();
  res.send({ message: 'Visitor count saved' });
});

app.post('/track-cart', async (req, res) => {
  const cartItem = new Cart(req.body);
  await cartItem.save();
  res.send({ message: 'Cart item saved' });
});

app.post('/submit-order', async (req, res) => {
  const order = new Order(req.body);
  await order.save();
  res.send({ message: 'Order placed successfully' });
});

app.get('/dashboard', async (req, res) => {
  const visitors = await Visitor.find();
  const cartItems = await Cart.find();
  const orders = await Order.find();
  res.send({ visitors, cartItems, orders });
});

// Start server
app.listen(port, () => {
  console.log(`Server running on port ${port}`);
});
